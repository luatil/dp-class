# This program implements a dp algorithm to find
# the best fingering for a sequence of notes on
# a single string. This is closely related to the
# piano case.

# fingers go from 0 to 4
# frets go from 0 to 4 // just head position

max_cost = 1e9

def transiton_cost(note1, finger1, note2, finger2) -> int:
    return abs( (finger2 - finger1) - (note2 - note1))

# def find_best_fingering(frets:[int], cost_f: Callable[[int, int, int, int], int]) -> [int]:
#    pass

# forgot about open strings
mapping = {}

def dp(i, j, notes) -> int:
    if i == len(notes) - 1: return 0
    if (i, j) not in mapping:
        mapping[(i, j)] = min(dp(i+1, k, notes) + transiton_cost(notes[i], j, notes[i+1], k) 
                              for k in range(4))
    return mapping[(i, j)]

