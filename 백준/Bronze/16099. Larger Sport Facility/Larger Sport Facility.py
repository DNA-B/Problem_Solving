test_case = int(input())

for _ in range (test_case):
    lt, wt, le, we = map(int, input().split())
    if lt * wt > le * we :
        print("TelecomParisTech")
    elif lt * wt < le * we :
        print("Eurecom")
    else :
        print("Tie")