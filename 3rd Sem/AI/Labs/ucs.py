% Direct enclosure facts
encloses(b1, b2).
encloses(b1, b5).
encloses(b2, b3).
encloses(b2, b4).
encloses(b5, b6).
encloses(b6, b7).

% Rule: Transitive enclosure
% If X encloses Y and Y encloses Z then X encloses Z
encloses(X, Z) :-
    encloses(X, Y),
    encloses(Y, Z).
