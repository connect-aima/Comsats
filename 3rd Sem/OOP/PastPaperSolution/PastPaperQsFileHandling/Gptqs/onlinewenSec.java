package Gptqs;
import java.util.*;
class Product{
    String productid;
    String productName;
    int basePrice;
    Seller s;//composition
    Product(String id,String n,int p){
        productid=id;
        productName=n;
        basePrice=p;
    }
}
class digitalProduct extends Product{
    String fileSize;
    digitalProduct(String id,String n,int p,String fz){
        super(id, n, p);
        fileSize=fz;
    }
}
class physicalProduct extends Product{
    int weight;
    int cost;
    physicalProduct(String id,String n,int p,int w,int c){
        super(id,n,p);
        weight=w;
        cost=c;
    }
}
class Seller{
    String sellerName;
    String sellerRatings;
    Seller(String n,String r){
        sellerName=n;
        sellerRatings=r;
    }
}
class onlineStore{
    ArrayList<Product> products;
    onlineStore(){
        new ArrayList<>();
    }
    void add(Product p){
        products.add(p);
    }
    
}
public class onlinewenSec {
    
}
