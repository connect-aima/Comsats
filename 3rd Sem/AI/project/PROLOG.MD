% =========================================
% WUMPUS WORLD KNOWLEDGE BASE (KB)
% =========================================
:- discontiguous pit/2.
% -----------------------------------------
% WORLD SIZE (4x4 GRID)
% -----------------------------------------
cell(X,Y) :-
    between(1,4,X),
    between(1,4,Y).

% -----------------------------------------
% OBSERVATIONS (FROM ENVIRONMENT)
% -----------------------------------------
breeze(2,1).
stench(1,2).

% -----------------------------------------
% KNOWN FACTS
% -----------------------------------------
pit(3,1).         % Given pit
safe(1,1).
safe(1,2).
safe(2,1).
safe(2,2).

% -----------------------------------------
% ADJACENCY (WITH BOUNDARY CHECK)
% -----------------------------------------
adjacent(X,Y,X1,Y) :-
    X1 is X+1,
    cell(X1,Y).

adjacent(X,Y,X1,Y) :-
    X1 is X-1,
    cell(X1,Y).

adjacent(X,Y,X,Y1) :-
    Y1 is Y+1,
    cell(X,Y1).

adjacent(X,Y,X,Y1) :-
    Y1 is Y-1,
    cell(X,Y1).

% -----------------------------------------
% PIT INFERENCE RULES
% -----------------------------------------

% A pit may exist in a cell if there is a breeze nearby
possible_pit(X,Y) :-
    breeze(A,B),
    adjacent(A,B,X,Y),
    cell(X,Y).

% No pit in safe cells
no_pit(X,Y) :-
    safe(X,Y).

% A pit exists only if it is possible and not proven absent
pit(X,Y) :-
    possible_pit(X,Y),
    \+ no_pit(X,Y).

% -----------------------------------------
% WUMPUS INFERENCE RULES
% -----------------------------------------

% A Wumpus may exist in a cell if there is a stench nearby
possible_wumpus(X,Y) :-
    stench(A,B),
    adjacent(A,B,X,Y),
    cell(X,Y).

% No Wumpus in safe cells
no_wumpus(X,Y) :-
    safe(X,Y).

% Wumpus exists in a cell if it is possible and not safe
wumpus(X,Y) :-
    possible_wumpus(X,Y),
    \+ no_wumpus(X,Y).

% -----------------------------------------
% QUERY HELPERS (FOR REPORT)
% -----------------------------------------

% Prove no pit in specific cells
no_pit_22 :-
    \+ pit(2,2).

no_pit_13 :-
    \+ pit(1,3).

% Prove Wumpus location
prove_wumpus :-
    wumpus(1,3).
