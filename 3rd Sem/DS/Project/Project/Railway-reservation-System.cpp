
#include <bits/stdc++.h>
using namespace std;

struct Passenger {
    int passengerID;
    string name, contact, status, trainID;
    time_t booking_time;
    int paidFare;
    Passenger(int id=0): passengerID(id), booking_time(0), paidFare(0) {}
};

struct PassengerNode {
    Passenger data;
    PassengerNode *next;
    PassengerNode(const Passenger &p): data(p), next(NULL) {}
};

struct WaitEntry {
    int paidFare;
    time_t booking_time;
    int passengerID;
    WaitEntry(int f=0,time_t bt=0,int pid=0):paidFare(f),booking_time(bt),passengerID(pid){}
    bool operator<(const WaitEntry &o) const {
        if(paidFare!=o.paidFare) return paidFare<o.paidFare;
        return booking_time>o.booking_time;
    }
};

struct Train {
    string trainID, source, destination;
    int totalSeats, availableSeats;
    int baseFare, currentFare;
    PassengerNode *passengerHead;
    priority_queue<WaitEntry> waitingList;
    Train():totalSeats(0),availableSeats(0),baseFare(0),currentFare(0),passengerHead(NULL){}
};

struct Action {
    string type; 
    int passengerID;
    string trainID;
    Passenger snapshot;
    int trainFareBefore;
};

class RailwaySystem {
    unordered_map<string, Train> trains;
    unordered_map<string,int> stationIndex;
    vector<string> indexToStation;
    vector<vector<pair<int,int>>> adj;
    set<pair<int,int>> damagedEdges;
    int nextPassengerID;
    stack<Action> undoStack, redoStack;
    priority_queue<pair<int,string>> demandHeap;
    unordered_map<string,int> demandScore;
    const int CANCEL_LIMIT_SECONDS = 300; // 5 minutes

public:
    RailwaySystem():nextPassengerID(1){
        ensureStation("A");ensureStation("B");ensureStation("C");
        ensureStation("D");ensureStation("E");ensureStation("F");
        addEdge("A","B",5);addEdge("A","C",10);addEdge("B","C",3);
        addEdge("B","D",7);addEdge("C","E",8);addEdge("D","E",2);addEdge("E","F",6);
        loadFromFile();
    }

    ~RailwaySystem() { saveToFile(); clearAllPassengers(); }

    void clearAllPassengers(){
        for(auto &kv:trains){
            PassengerNode *cur=kv.second.passengerHead;
            while(cur){ PassengerNode *n=cur->next; delete cur; cur=n; }
            kv.second.passengerHead=NULL;
        }
    }

  
    void saveToFile() {
    ofstream out("rail_data.txt");

    out << "==================== STATIONS ====================\n";
    out << left << setw(8) << "Index" << "| Name\n";
    out << "-----------------------------\n";
    for (size_t i = 0; i < indexToStation.size(); i++) {
        out << setw(8) << i << "| " << indexToStation[i] << "\n";
    }
    out << "\n";

    out << "==================== EDGES ====================\n";
    out << left << setw(6) << "From" << "| "
        << setw(6) << "To" << "| "
        << setw(8) << "Weight" << "| Status\n";
    out << "------------------------------------------\n";

    for (size_t u = 0; u < adj.size(); u++) {
        for (auto &e : adj[u]) {
            if ((int)u < e.first) {
                bool damaged = damagedEdges.count(make_ordered_pair(u, e.first));
                out << setw(6) << indexToStation[u] << "| "
                    << setw(6) << indexToStation[e.first] << "| "
                    << setw(8) << e.second << "| "
                    << (damaged ? "DAMAGED" : "OK") << "\n";
            }
        }
    }
    out << "\n";

    out << "==================== TRAINS ====================\n";
    out << left
        << setw(8) << "TrainID" << "| "
        << setw(8) << "Source" << "| "
        << setw(12) << "Destination" << "| "
        << setw(6) << "Seats" << "| "
        << setw(10) << "Available" << "| "
        << setw(8) << "Base" << "| "
        << setw(10) << "Current" << "| Demand\n";
    out << "----------------------------------------------------------------------------\n";

    for (auto &kv : trains) {
        Train &t = kv.second;
        out << setw(8) << t.trainID << "| "
            << setw(8) << t.source << "| "
            << setw(12) << t.destination << "| "
            << setw(6) << t.totalSeats << "| "
            << setw(10) << t.availableSeats << "| "
            << setw(8) << t.baseFare << "| "
            << setw(10) << t.currentFare << "| "
            << demandScore[t.trainID] << "\n";

        out << "\nPassengers (Train " << t.trainID << "):\n";
        out << left
            << setw(4) << "ID" << "| "
            << setw(10) << "Name" << "| "
            << setw(10) << "Contact" << "| "
            << setw(10) << "Status" << "| "
            << setw(12) << "Time" << "| Fare\n";
        out << "-----------------------------------------------------------\n";

        for (PassengerNode *cur = t.passengerHead; cur; cur = cur->next) {
            Passenger &p = cur->data;
            out << setw(4) << p.passengerID << "| "
                << setw(10) << p.name << "| "
                << setw(10) << p.contact << "| "
                << setw(10) << p.status << "| "
                << setw(12) << (long long)p.booking_time << "| "
                << p.paidFare << "\n";
        }

        out << "\nWaiting List:\n";
        out << left
            << setw(12) << "PaidFare" << "| "
            << setw(12) << "Time" << "| PassengerID\n";
        out << "----------------------------------------\n";

        priority_queue<WaitEntry> tmp = t.waitingList;
        while (!tmp.empty()) {
            auto w = tmp.top(); tmp.pop();
            out << setw(12) << w.paidFare << "| "
                << setw(12) << (long long)w.booking_time << "| "
                << w.passengerID << "\n";
        }

        out << "\n====================================================\n\n";
    }
}


    void loadFromFile(){
        ifstream in("rail_data.txt");
        if(!in) return;
        clearAllPassengers(); trains.clear(); stationIndex.clear(); indexToStation.clear(); 
        adj.clear(); damagedEdges.clear(); demandHeap=priority_queue<pair<int,string>>();
        demandScore.clear();
        int N; in>>nextPassengerID>>N;
        for(int i=0;i<N;++i){ string s; in>>s; stationIndex[s]=i; indexToStation.push_back(s); }
        int adjN; in>>adjN; adj.assign(adjN,vector<pair<int,int>>());
        for(int u=0;u<adjN;++u){
            int m; in>>m; for(int i=0;i<m;++i){ int v,w; in>>v>>w; adj[u].push_back({v,w}); }
        }
        int dcnt; in>>dcnt; for(int i=0;i<dcnt;++i){ int a,b; in>>a>>b; damagedEdges.insert({a,b}); }
        int tcnt; in>>tcnt;
        for(int i=0;i<tcnt;++i){
            Train t; in>>t.trainID>>t.source>>t.destination>>t.totalSeats>>t.availableSeats>>t.baseFare>>t.currentFare;
            int pcnt; in>>pcnt;
            PassengerNode *head=NULL,*tail=NULL;
            for(int j=0;j<pcnt;++j){
                Passenger p; long long bt; string stat;
                in>>p.passengerID>>p.name>>p.contact>>p.trainID>>stat>>bt>>p.paidFare;
                p.status=stat; p.booking_time=(time_t)bt;
                PassengerNode *node=new PassengerNode(p);
                if(!head) head=tail=node; else{ tail->next=node; tail=node; }
            }
            t.passengerHead=head;
            int wcnt; in>>wcnt;
            for(int j=0;j<wcnt;++j){
                int pf,pid; long long bt; in>>pf>>bt>>pid;
                t.waitingList.push(WaitEntry(pf,(time_t)bt,pid));
            }
            trains[t.trainID]=t;
        }
        int dsz; in>>dsz;
        for(int i=0;i<dsz;++i){ string tid; int sc; in>>tid>>sc; demandScore[tid]=sc; demandHeap.push({sc,tid}); }
    }

    void ensureStation(const string &st){
        if(stationIndex.count(st)) return;
        int idx=indexToStation.size();
        stationIndex[st]=idx; indexToStation.push_back(st);
        adj.push_back(vector<pair<int,int>>());
    }

    void addEdge(const string &a,const string &b,int w){
        ensureStation(a);ensureStation(b);
        int ia=stationIndex[a], ib=stationIndex[b];
        adj[ia].push_back({ib,w}); adj[ib].push_back({ia,w});
    }

    pair<int,int> make_ordered_pair(int a,int b){ 
        return (a<=b)?make_pair(a,b):make_pair(b,a); 
    }

    Passenger* findPassenger(Train &t,int pid,PassengerNode **prev=NULL,PassengerNode **node=NULL){
        PassengerNode *cur=t.passengerHead,*pr=NULL;
        while(cur){
            if(cur->data.passengerID==pid){
                if(prev) *prev=pr; if(node) *node=cur;
                return &cur->data;
            }
            pr=cur;cur=cur->next;
        }
        return NULL;
    }

    void removePassengerNode(Train &t,int pid){
        PassengerNode *cur=t.passengerHead,*pr=NULL;
        while(cur){
            if(cur->data.passengerID==pid){
                if(pr) pr->next=cur->next; else t.passengerHead=cur->next;
                delete cur; return;
            }
            pr=cur;cur=cur->next;
        }
    }

    void insertPassengerNode(Train &t,const Passenger &p){
        PassengerNode *node=new PassengerNode(p);
        node->next=t.passengerHead; t.passengerHead=node;
    }

    void updateDemand(const string &trainID,int delta){
        int &val=demandScore[trainID];
        val+=delta; if(val<0) val=0;
        demandHeap.push({val,trainID});
        Train &t=trains[trainID];
        t.currentFare = t.baseFare + val*50;
        if(t.currentFare < t.baseFare) t.currentFare=t.baseFare;
    }

  
    void addTrain(){
        Train t;
        cout<<"Enter train ID: ";cin>>t.trainID;
        cout<<"Source station name: ";cin>>t.source;
        cout<<"Destination station name: ";cin>>t.destination;
        cout<<"Total seats: ";cin>>t.totalSeats;
        cout<<"Base fare (integer): ";cin>>t.baseFare;
        t.availableSeats=t.totalSeats; t.currentFare=t.baseFare;
        trains[t.trainID]=t;
        ensureStation(t.source);ensureStation(t.destination);
        demandScore[t.trainID]=0;
        cout<<"Train "<<t.trainID<<" added.\n";
        saveToFile();  
    }

    void listTrains(){
        if(trains.empty()){ cout<<"No trains available.\n"; return; }
        cout<<"TrainID | Source->Dest | avail/total | BaseFare | CurrentFare | Demand\n";
        for(auto &kv:trains){
            Train &t=kv.second;
            cout<<t.trainID<<" | "<<t.source<<"->"<<t.destination
                <<" | "<<t.availableSeats<<"/"<<t.totalSeats
                <<" | "<<t.baseFare<<" | "<<t.currentFare
                <<" | "<<demandScore[t.trainID]<<"\n";
        }
    }

    void listAvailableTrains(){ 
        bool any=false;
        cout<<"Trains with available seats:\n";
        for(auto &kv:trains){
            Train &t=kv.second;
            if(t.availableSeats>0){
                any=true;
                cout<<t.trainID<<" | "<<t.source<<"->"<<t.destination
                    <<" | "<<t.availableSeats<<"/"<<t.totalSeats
                    <<" | Base: "<<t.baseFare<<" | Current: "<<t.currentFare<<"\n";
            }
        }
        if(!any) cout<<"No trains currently have free seats.\n";
    }

    void bookTicketForPassenger(){
        string trainID; cout<<"Enter train ID to book: ";cin>>trainID;
        auto it=trains.find(trainID);
        if(it==trains.end()){ cout<<"Train not found.\n";return; }
        Train &t=it->second;
        Passenger p(nextPassengerID++);
        cout<<"Passenger name: ";cin>>p.name;
        cout<<"Passenger contact: ";cin>>p.contact;
        p.trainID=trainID; p.booking_time=time(NULL);
        int extra=0; cout<<"Extra for priority (0=none): ";cin>>extra; if(extra<0) extra=0;
        cout << "Ticket price (demand-based): "<< t.currentFare << endl;
        p.paidFare = t.currentFare + extra;       
        updateDemand(trainID, 1); 

        if(t.availableSeats>0){
            p.status="Confirmed";
            insertPassengerNode(t,p);
            t.availableSeats--;
            Action a; a.type="BOOK_CONFIRM"; a.passengerID=p.passengerID; a.trainID=trainID;
            a.snapshot=p; a.trainFareBefore=t.currentFare;
            undoStack.push(a); while(!redoStack.empty()) redoStack.pop();
            cout<<"Booking confirmed. ID: "<<p.passengerID<<" Paid: "<<p.paidFare<<"\n";
        }else{
            p.status="Waiting";
            insertPassengerNode(t,p);
            t.waitingList.push(WaitEntry(p.paidFare,p.booking_time,p.passengerID));
            Action a; a.type="BOOK_WAIT"; a.passengerID=p.passengerID; a.trainID=trainID;
            a.snapshot=p; a.trainFareBefore=t.currentFare;
            undoStack.push(a); while(!redoStack.empty()) redoStack.pop();
            cout<<"Added to waiting list. ID: "<<p.passengerID<<"\n";
        }
        saveToFile();  
    }

    void cancelTicketForPassenger(){
        string trainID; int pid;
        cout<<"Enter train ID: ";cin>>trainID;
        cout<<"Enter passenger ID: ";cin>>pid;
        auto it=trains.find(trainID);
        if(it==trains.end()){ cout<<"Train not found.\n";return; }
        Train &t=it->second;
        Passenger *pp=findPassenger(t,pid);
        if(!pp){ cout<<"Passenger not found.\n";return; }
        time_t now=time(NULL);
        if(difftime(now,pp->booking_time)>CANCEL_LIMIT_SECONDS){
            cout<<"Cancellation not allowed: >"<<CANCEL_LIMIT_SECONDS<<"s since booking.\n";
            return;
        }
        Passenger p=*pp;
        if(p.status=="Confirmed"){
            removePassengerNode(t,pid);
            t.availableSeats++;
            updateDemand(trainID,-1);
            assignSeatFromWaiting(t);
        }else{
            removePassengerNode(t,pid);
        }
        Action a; a.type="CANCEL"; a.passengerID=pid; a.trainID=trainID;
        a.snapshot=p; a.trainFareBefore=t.currentFare;
        undoStack.push(a); while(!redoStack.empty()) redoStack.pop();
        cout<<"Cancellation successful for "<<pid<<".\n";
        saveToFile(); 
    }

    void assignSeatFromWaiting(Train &t){
        while(t.availableSeats>0 && !t.waitingList.empty()){
            WaitEntry top=t.waitingList.top(); t.waitingList.pop();
            Passenger *wp=findPassenger(t,top.passengerID);
            if(wp && wp->status=="Waiting"){
                wp->status="Confirmed";
                t.availableSeats--;
                break;
            }
        }
    }

    void undo(){
        if(undoStack.empty()){ cout<<"Nothing to undo.\n"; return; }
        Action a=undoStack.top(); undoStack.pop();
        Train &t=trains[a.trainID];
        if(a.type=="BOOK_CONFIRM"){
            removePassengerNode(t,a.passengerID);
            t.availableSeats++;
            updateDemand(a.trainID,-1);
            redoStack.push(a);
            cout<<"Undo: removed confirmed booking "<<a.passengerID<<".\n";
        }else if(a.type=="BOOK_WAIT"){
            removePassengerNode(t,a.passengerID);
            redoStack.push(a);
            cout<<"Undo: removed waiting booking "<<a.passengerID<<".\n";
        }else if(a.type=="CANCEL"){
            Passenger p=a.snapshot;
            if(p.status=="Confirmed" && t.availableSeats>0){
                insertPassengerNode(t,p);
                t.availableSeats--;
                updateDemand(a.trainID,1);
            }else{
                p.status="Waiting";
                insertPassengerNode(t,p);
                t.waitingList.push(WaitEntry(p.paidFare,p.booking_time,p.passengerID));
            }
            redoStack.push(a);
            cout<<"Undo: restored passenger "<<p.passengerID<<".\n";
        }
        saveToFile(); 
    }

    void redo(){
        if(redoStack.empty()){ cout<<"Nothing to redo.\n"; return; }
        Action a=redoStack.top(); redoStack.pop();
        Train &t=trains[a.trainID];
        if(a.type=="BOOK_CONFIRM"){
            insertPassengerNode(t,a.snapshot);
            if(t.availableSeats>0){ t.availableSeats--; updateDemand(a.trainID,1); }
            undoStack.push(a);
            cout<<"Redo: confirmed booking "<<a.passengerID<<".\n";
        }else if(a.type=="BOOK_WAIT"){
            insertPassengerNode(t,a.snapshot);
            t.waitingList.push(WaitEntry(a.snapshot.paidFare,a.snapshot.booking_time,a.passengerID));
            undoStack.push(a);
            cout<<"Redo: waiting booking "<<a.passengerID<<".\n";
        }else if(a.type=="CANCEL"){
            Passenger *pp=findPassenger(t,a.passengerID);
            if(pp && pp->status=="Confirmed"){
                removePassengerNode(t,a.passengerID);
                t.availableSeats++;
                updateDemand(a.trainID,-1);
                assignSeatFromWaiting(t);
            }else if(pp){
                removePassengerNode(t,a.passengerID);
            }
            undoStack.push(a);
            cout<<"Redo: cancellation "<<a.passengerID<<".\n";
        }
        saveToFile();  
    }

    
    void addEdgeBetweenStations(){
        string a,b; int w;
        cout<<"Station A: ";cin>>a; cout<<"Station B: ";cin>>b; cout<<"Weight: ";cin>>w;
        addEdge(a,b,w);
        cout<<"Edge added.\n";
        saveToFile();
    }

    void showStationsAndEdges(){
        cout<<"Stations:\n";
        for(size_t i=0;i<indexToStation.size();++i) cout<<i<<": "<<indexToStation[i]<<"\n";
        cout<<"Edges:\n";
        for(size_t u=0;u<adj.size();++u)
            for(auto &e:adj[u])
                if((int)u<e.first)
                    cout<<indexToStation[u]<<" --("<<e.second<<")-- "<<indexToStation[e.first]<<"\n";
    }

    void markEdgeDamaged(){
        string a,b; cout<<"Station A: ";cin>>a; cout<<"Station B: ";cin>>b;
        if(!stationIndex.count(a)||!stationIndex.count(b)){ cout<<"Unknown station.\n";return; }
        damagedEdges.insert(make_ordered_pair(stationIndex[a],stationIndex[b]));
        cout<<"Edge marked damaged.\n";
        saveToFile();
    }

    void repairEdge(){
        string a,b; cout<<"Station A: ";cin>>a; cout<<"Station B: ";cin>>b;
        if(!stationIndex.count(a)||!stationIndex.count(b)){ cout<<"Unknown station.\n";return; }
        auto pr=make_ordered_pair(stationIndex[a],stationIndex[b]);
        if(damagedEdges.erase(pr)) cout<<"Edge repaired.\n"; else cout<<"Not damaged.\n";
        saveToFile();
    }

   pair<long long,vector<int>> dijkstraAvoidingDamaged(int src,int dst){
    const long long INF=numeric_limits<long long>::max()/4;
    int n=adj.size();
    vector<long long> dist(n,INF); 
    vector<int> par(n,-1);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    dist[src]=0; 
    pq.push(make_pair(0,src));
    
    while(!pq.empty()){
        pair<long long,int> cur = pq.top(); pq.pop();
        long long d = cur.first;
        int u = cur.second;
        
        if(d != dist[u]) continue;
        if(u == dst) break;
        
        for(auto &e : adj[u]){
            int v = e.first;
            int w = e.second;
            if(damagedEdges.count(make_ordered_pair(u,v))) continue;
            if(dist[v] > dist[u] + w){ 
                dist[v] = dist[u] + w; 
                par[v] = u; 
                pq.push(make_pair(dist[v],v)); 
            }
        }
    }
    if(dist[dst] >= INF) return make_pair(-1LL,vector<int>());
    
    vector<int> path; 
    int cur = dst;
    while(cur != -1){ 
        path.push_back(cur); 
        cur = par[cur]; 
    }
    reverse(path.begin(),path.end());
    return make_pair(dist[dst],path);
}


    void printPath(const vector<int> &path){
        for(size_t i=0;i<path.size();++i){
            cout<<indexToStation[path[i]];
            if(i+1<path.size()) cout<<" -> ";
        }
        cout<<"\n";
    }

    void findRouteInterface(){
        string sname,dname;
        cout<<"Source station: ";cin>>sname; cout<<"Destination: ";cin>>dname;
        if(!stationIndex.count(sname)||!stationIndex.count(dname)){
            cout<<"Unknown stations.\n"; return;
        }
        int s=stationIndex[sname], d=stationIndex[dname];
        auto res=dijkstraAvoidingDamaged(s,d);
        if(res.first<0){ cout<<"No path available.\n"; return; }
        cout<<"Distance: "<<res.first<<"\nPath: "; printPath(res.second);
        auto saved=damagedEdges; damagedEdges.clear();
        auto original=dijkstraAvoidingDamaged(s,d);
        damagedEdges=saved;
        bool origDamaged=false;
        for(size_t i=0;i+1<original.second.size();++i){
            if(saved.count(make_ordered_pair(original.second[i],original.second[i+1]))) origDamaged=true;
        }
        if(origDamaged) cout<<"Original path damaged. Above is alternative.\n";
        else cout<<"Original route undamaged.\n";
    }

    void showTrainPassengers(){
        string trainID; cout<<"Enter train ID: ";cin>>trainID;
        auto it=trains.find(trainID);
        if(it==trains.end()){ cout<<"Train not found.\n"; return; }
        Train &t=it->second;
        cout<<"Passengers for "<<trainID<<":\n";
        for(PassengerNode *cur=t.passengerHead;cur;cur=cur->next){
            auto &p=cur->data;
            cout<<"ID:"<<p.passengerID<<" "<<p.name<<" "<<p.status
                <<" Time:"<<(long long)p.booking_time<<" Fare:"<<p.paidFare<<"\n";
        }
    }

    void menu(){
        while(true){
            cout<<"\n=== Dynamic Railway Reservation System ===\n";
            cout<<"1. Add Train\n2. List All Trains\n3. List Available Trains\n";
            cout<<"4. Book Ticket\n5. Cancel Ticket\n6. Undo\n7. Redo\n";
            cout<<"8. Add Station Edge\n9. Show Stations/Edges\n10. Mark Edge Damaged\n";
            cout<<"11. Repair Edge\n12. Find Route/Alternative\n13. Show Passengers\n";
            cout<<"0. Exit\nSelect: ";
            int opt; if(!(cin>>opt)) break;
            switch(opt){
                case 1: addTrain(); break;
                case 2: listTrains(); break;
                case 3: listAvailableTrains(); break;
                case 4: bookTicketForPassenger(); break;
                case 5: cancelTicketForPassenger(); break;
                case 6: undo(); break;
                case 7: redo(); break;
                case 8: addEdgeBetweenStations(); break;
                case 9: showStationsAndEdges(); break;
                case 10: markEdgeDamaged(); break;
                case 11: repairEdge(); break;
                case 12: findRouteInterface(); break;
                case 13: showTrainPassengers(); break;
                case 0: saveToFile(); cout<<"Data saved. Goodbye!\n"; return;
                default: cout<<"Invalid option.\n";
            }
        }
    }
};

int main(){
    cout<<"Dynamic Railway Reservation System - All Features Active\n";
    RailwaySystem sys;
    sys.menu();
    return 0;
}
