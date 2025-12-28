% Parent facts
parent(albert, bob).
parent(albert, charlie).
parent(bob, carl).
parent(bob, dave).

% Male facts
male(albert).
male(bob).
male(charlie).
male(carl).
male(dave).
brother(X, Y) :-
    male(X),
    parent(P, X),
    parent(P, Y),
    X \= Y.
uncle(U, X) :-
    parent(P, X),
    brother(U, P).
