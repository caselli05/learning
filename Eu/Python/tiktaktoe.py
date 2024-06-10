def main():
    pos = {0, 0, 0, 0, 0, 0, 0, 0, 0}
    draw(pos)


     

    return

def draw(pos):
    # linha 1
    for i in range(5):
        if i%2 != 0:
            for j in range(5):
                if j%2 != 0:
                    k = pos[j // 2]
                    if k == 0:
                        print(" ", end="")
                    elif k == 1:
                        print("X", end="")
                    else:
                        print("O", end="")
                else:
                    print("|", end="")
        else:
            print("-+-+-", end="")
        print()

        

    



















main()