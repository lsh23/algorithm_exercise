def solution(skill, skill_trees):
    answer = 0
    s_i = {}
    i = 0
    for c in skill:
        s_i[c]=i
        i +=1

    for skill_tree in skill_trees:
        j = 0
        valid = True
        for s in skill_tree:
            if s in s_i:
                if(s_i[s]==j):
                    j=j+1
                else:
                    valid = False
                    break
        if valid:
            answer += 1

    return answer