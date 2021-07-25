# 1- cercle vers droite
# 2- avancé
# 3- carré vers gauche
# 4- triangle vers gauche
# 5- reculer
# 6- carré vers droite
# 7- 90° à gauche
# 8- 90° à droite
# 9- triangle vers droite
# 10- cercle vers gauche
# Pour utiliser ce programme la trame doit être composée de 16 nombres chacuns séparé par des espaces. La trame commencera par un nombre et non un espace
from turtle import *
color("black","red")
z = 0
while z < 16:
    tab = input("La trame reçue est : ").split()
    for i in range(len(tab)):
        tab[i] = int(tab[i])
    if tab[0] == 1:
        circle(60)
        z = z + 1

    elif tab[0] == 2:
        forward(120)
        z = z + 1

    elif tab[0] == 3:
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        z = z + 1

    elif tab[0] == 4:
        forward(120)
        left(120)
        forward(120)
        left(120)
        forward(120)
        z = z + 1

    elif tab[0] == 5:
        backward(120)
        z = z + 1

    elif tab[0] == 6:
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        z = z + 1

    elif tab[0] == 7:
        left(90)
        z = z + 1

    elif tab[0] == 8:
        right(90)
        z = z + 1
    elif tab[0] == 9:
        forward(120)
        right(120)
        forward(120)
        right(120)
        forward(120)
        z = z + 1
    if tab[0] == 10:
        circle(-60)
        z = z + 1

    if tab[1] == 1:
        circle(60)
        z = z + 1

    elif tab[1] == 2:
        forward(120)
        z = z + 1

    elif tab[1] == 3:
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        z = z + 1

    elif tab[1] == 4:
        forward(120)
        left(120)
        forward(120)
        left(120)
        forward(120)
        z = z + 1

    elif tab[1] == 5:
        backward(120)
        z = z + 1

    elif tab[1] == 6:
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        z = z + 1

    elif tab[1] == 7:
        left(90)
        z = z + 1

    elif tab[1] == 8:
        right(90)
        z = z + 1
    elif tab[1] == 9:
        forward(120)
        right(120)
        forward(120)
        right(120)
        forward(120)
        z = z + 1
    if tab[1] == 10:
        circle(-60)
        z = z + 1

    if tab[2] == 1:
        circle(60)
        z = z + 1

    elif tab[2] == 2:
        forward(120)
        z = z + 1

    elif tab[2] == 3:
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        z = z + 1

    elif tab[2] == 4:
        forward(120)
        left(120)
        forward(120)
        left(120)
        forward(120)
        z = z + 1

    elif tab[2] == 5:
        backward(120)
        z = z + 1

    elif tab[2] == 6:
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        z = z + 1

    elif tab[2] == 7:
        left(90)
        z = z + 1

    elif tab[2] == 8:
        right(90)
        z = z + 1
    elif tab[2] == 9:
        forward(120)
        right(120)
        forward(120)
        right(120)
        forward(120)
        z = z + 1
        
    if tab[2] == 10:
        circle(-60)
        z = z + 1

    if tab[3] == 1:
        circle(60)
        z = z + 1

    elif tab[3] == 2:
        forward(120)
        z = z + 1

    elif tab[3] == 3:
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        z = z + 1

    elif tab[3] == 4:
        forward(120)
        left(120)
        forward(120)
        left(120)
        forward(120)
        z = z + 1

    elif tab[3] == 5:
        backward(120)
        z = z + 1

    elif tab[3] == 6:
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        z = z + 1

    elif tab[3] == 7:
        left(90)
        z = z + 1

    elif tab[3] == 8:
        right(90)
        z = z + 1
    elif tab[3] == 9:
        forward(120)
        right(120)
        forward(120)
        right(120)
        forward(120)
        z = z + 1

    if tab[4] == 1:
        circle(60)
        z = z + 1

    elif tab[4] == 2:
        forward(120)
        z = z + 1

    elif tab[4] == 3:
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        z = z + 1

    elif tab[4] == 4:
        forward(120)
        left(120)
        forward(120)
        left(120)
        forward(120)
        z = z + 1

    elif tab[4] == 5:
        backward(120)
        z = z + 1

    elif tab[4] == 6:
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        z = z + 1

    elif tab[4] == 7:
        left(90)
        z = z + 1

    elif tab[4] == 8:
        right(90)
        z = z + 1
    elif tab[4] == 9:
        forward(120)
        right(120)
        forward(120)
        right(120)
        forward(120)
        z = z + 1
    if tab[5] == 1:
        circle(60)
        z = z + 1

    elif tab[5] == 2:
        forward(120)
        z = z + 1

    elif tab[5] == 3:
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        z = z + 1

    elif tab[5] == 4:
        forward(120)
        left(120)
        forward(120)
        left(120)
        forward(120)
        z = z + 1

    elif tab[5] == 5:
        backward(120)
        z = z + 1

    elif tab[5] == 6:
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        z = z + 1

    elif tab[5] == 7:
        left(90)
        z = z + 1

    elif tab[5] == 8:
        right(90)
        z = z + 1
    elif tab[5] == 9:
        forward(120)
        right(120)
        forward(120)
        right(120)
        forward(120)
        z = z + 1
    if tab[6] == 1:
        circle(60)
        z = z + 1

    elif tab[6] == 2:
        forward(120)
        z = z + 1

    elif tab[6] == 3:
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        z = z + 1

    elif tab[6] == 4:
        forward(120)
        left(120)
        forward(120)
        left(120)
        forward(120)
        z = z + 1

    elif tab[6] == 5:
        backward(120)
        z = z + 1

    elif tab[6] == 6:
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        z = z + 1

    elif tab[6] == 7:
        left(90)
        z = z + 1

    elif tab[6] == 8:
        right(90)
        z = z + 1
    elif tab[6] == 9:
        forward(120)
        right(120)
        forward(120)
        right(120)
        forward(120)
        z = z + 1
    if tab[7] == 1:
        circle(60)
        z = z + 1

    elif tab[7] == 2:
        forward(120)
        z = z + 1

    elif tab[7] == 3:
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        z = z + 1

    elif tab[7] == 4:
        forward(120)
        left(120)
        forward(120)
        left(120)
        forward(120)
        z = z + 1

    elif tab[7] == 5:
        backward(120)
        z = z + 1

    elif tab[7] == 6:
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        z = z + 1

    elif tab[7] == 7:
        left(90)
        z = z + 1

    elif tab[7] == 8:
        right(90)
        z = z + 1
    elif tab[7] == 9:
        forward(120)
        right(120)
        forward(120)
        right(120)
        forward(120)
        z = z + 1
    if tab[8] == 1:
        circle(60)
        z = z + 1

    elif tab[8] == 2:
        forward(120)
        z = z + 1

    elif tab[8] == 3:
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        z = z + 1

    elif tab[8] == 4:
        forward(120)
        left(120)
        forward(120)
        left(120)
        forward(120)
        z = z + 1

    elif tab[8] == 5:
        backward(120)
        z = z + 1

    elif tab[8] == 6:
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        z = z + 1

    elif tab[9] == 7:
        left(90)
        z = z + 1

    elif tab[8] == 8:
        right(90)
        z = z + 1
    elif tab[8] == 9:
        forward(120)
        right(120)
        forward(120)
        right(120)
        forward(120)
        z = z + 1
    if tab[9] == 1:
        circle(60)
        z = z + 1

    elif tab[9] == 2:
        forward(120)
        z = z + 1

    elif tab[9] == 3:
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        z = z + 1

    elif tab[9] == 4:
        forward(120)
        left(120)
        forward(120)
        left(120)
        forward(120)
        z = z + 1

    elif tab[9] == 5:
        backward(120)
        z = z + 1

    elif tab[9] == 6:
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        z = z + 1

    elif tab[9] == 7:
        left(90)
        z = z + 1

    elif tab[9] == 8:
        right(90)
        z = z + 1
    elif tab[9] == 9:
        forward(120)
        right(120)
        forward(120)
        right(120)
        forward(120)
        z = z + 1
    if tab[10] == 1:
        circle(60)
        z = z + 1

    elif tab[10] == 2:
        forward(120)
        z = z + 1

    elif tab[10] == 3:
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        z = z + 1

    elif tab[10] == 4:
        forward(120)
        left(120)
        forward(120)
        left(120)
        forward(120)
        z = z + 1

    elif tab[10] == 5:
        backward(120)
        z = z + 1

    elif tab[10] == 6:
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        z = z + 1

    elif tab[10] == 7:
        left(90)
        z = z + 1

    elif tab[10] == 8:
        right(90)
        z = z + 1
    elif tab[10] == 9:
        forward(120)
        right(120)
        forward(120)
        right(120)
        forward(120)
        z = z + 1
    if tab[11] == 1:
        circle(60)
        z = z + 1

    elif tab[11] == 2:
        forward(120)
        z = z + 1

    elif tab[11] == 3:
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        z = z + 1

    elif tab[11] == 4:
        forward(120)
        left(120)
        forward(120)
        left(120)
        forward(120)
        z = z + 1

    elif tab[11] == 5:
        backward(120)
        z = z + 1

    elif tab[11] == 6:
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        z = z + 1

    elif tab[11] == 7:
        left(90)
        z = z + 1

    elif tab[11] == 8:
        right(90)
        z = z + 1
    elif tab[11] == 9:
        forward(120)
        right(120)
        forward(120)
        right(120)
        forward(120)
        z = z + 1
    if tab[12] == 1:
        circle(60)
        z = z + 1

    elif tab[12] == 2:
        forward(120)
        z = z + 1

    elif tab[12] == 3:
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        z = z + 1

    elif tab[12] == 4:
        forward(120)
        left(120)
        forward(120)
        left(120)
        forward(120)
        z = z + 1

    elif tab[12] == 5:
        backward(120)
        z = z + 1

    elif tab[12] == 6:
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        z = z + 1

    elif tab[12] == 7:
        left(90)
        z = z + 1

    elif tab[12] == 8:
        right(90)
        z = z + 1
    elif tab[12] == 9:
        forward(120)
        right(120)
        forward(120)
        right(120)
        forward(120)
        z = z + 1
    if tab[13] == 1:
        circle(60)
        z = z + 1

    elif tab[13] == 2:
        forward(120)
        z = z + 1

    elif tab[13] == 3:
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        z = z + 1

    elif tab[13] == 4:
        forward(120)
        left(120)
        forward(120)
        left(120)
        forward(120)
        z = z + 1

    elif tab[13] == 5:
        backward(120)
        z = z + 1

    elif tab[13] == 6:
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        z = z + 1

    elif tab[13] == 7:
        left(90)
        z = z + 1

    elif tab[13] == 8:
        right(90)
        z = z + 1
    elif tab[13] == 9:
        forward(120)
        right(120)
        forward(120)
        right(120)
        forward(120)
        z = z + 1
    if tab[14] == 1:
        circle(60)
        z = z + 1

    elif tab[14] == 2:
        forward(120)
        z = z + 1

    elif tab[14] == 3:
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        z = z + 1

    elif tab[14] == 4:
        forward(120)
        left(120)
        forward(120)
        left(120)
        forward(120)
        z = z + 1

    elif tab[14] == 5:
        backward(120)
        z = z + 1

    elif tab[14] == 6:
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        z = z + 1

    elif tab[14] == 7:
        left(90)
        z = z + 1

    elif tab[14] == 8:
        right(90)
        z = z + 1
    elif tab[14] == 9:
        forward(120)
        right(120)
        forward(120)
        right(120)
        forward(120)
        z = z + 1
    if tab[15] == 1:
        circle(60)
        z = z + 1

    elif tab[15] == 2:
        forward(120)
        z = z + 1

    elif tab[15] == 3:
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        left(90)
        forward(120)
        z = z + 1

    elif tab[15] == 4:
        forward(120)
        left(120)
        forward(120)
        left(120)
        forward(120)
        z = z + 1

    elif tab[15] == 5:
        backward(120)
        z = z + 1

    elif tab[15] == 6:
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        right(90)
        forward(120)
        z = z + 1

    elif tab[15] == 7:
        left(90)
        z = z + 1

    elif tab[15] == 8:
        right(90)
        z = z + 1
    elif tab[15] == 9:
        forward(120)
        right(120)
        forward(120)
        right(120)
        forward(120)
        z = z + 1
    z = z - 16
