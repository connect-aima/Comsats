parent(albert, bob).
parent(albert, charlie).

parent(bob, carl).
parent(bob, dave).

parent(charlie, emma).
parent(charlie, frank).
grandparent(GP, GC) :-
    parent(GP, P),
    parent(P, GC).
