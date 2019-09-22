import sys

def leerArchivo():
    archivo = sys.argv[1]
    f = open (archivo,'r')
    mensaje = f.read()
    mensaje=mensaje.replace(" ","")
    mensaje=mensaje.replace("\n","")
    mensaje=mensaje.replace(".",'0')
    f.close()
    return mensaje

def formateo():
    archivoLeido=leerArchivo()
    lista=[]
    for elemento in archivoLeido:
        lista.append(elemento)
    return lista

def matrizMapa(lista,renglones,columnas):
    mapa=[]
    for i in range(renglones):
        mapa.append([])
        for j in range(columnas):
            elemento=lista.pop(0)
            if elemento == '0':
                mapa[i].append(int(elemento))
            else:
                mapa[i].append(elemento)
    return mapa

def imprimirMapa(mapa,renglones,columnas):
    for i in range(renglones):
        for j in range(columnas):
            print(mapa[i][j],end="")
        print("")

def check(mapa,i,j):
    #print("->",i,j)
    if mapa[i][j]  == '*':
        mapa[i][j]  = '*'   
    else:
        mapa[i][j] +=1

def bombasActivas(mapa,renglones,columnas):
    for i in range(renglones):
        for j in range(columnas):
            if i==0 and j==0:
                if mapa[i][j] == '*':
                    check(mapa,i,j+1)
                    check(mapa,i+1,j+1)
                    check(mapa,i+1,j)
            elif(i==renglones-1 and j==columnas-1):
                if mapa[i][j] == '*':
                    check(mapa,i,j-1)
                    check(mapa,i-1,j-1)
                    check(mapa,i-1,j)
            elif(i==renglones-1 and j==0):
                if mapa[i][j] == '*':
                    check(mapa,i,j+1)
                    check(mapa,i-1,j)
                    check(mapa,i-1,j+1)
            elif(i==0 and j==columnas-1):
                if mapa[i][j] == '*':
                    check(mapa,i,j-1)
                    check(mapa,i+1,j)
                    check(mapa,i+1,j-1)
            elif(i>0 and j==0):
                if mapa[i][j] == '*':
                    check(mapa,i,j+1)
                    check(mapa,i+1,j)
                    check(mapa,i-1,j)
                    check(mapa,i+1,j+1)
                    check(mapa,i-1,j+1)
            elif(i==0 and j>0):
                if mapa[i][j] == '*':
                    check(mapa,i,j+1)
                    check(mapa,i,j-1)
                    check(mapa,i+1,j)
                    check(mapa,i+1,j-1)
                    check(mapa,i+1,j+1)
            elif(i==renglones-1 and j>0):
                if mapa[i][j] == '*':
                    check(mapa,i-1,j)
                    check(mapa,i,j-1)
                    check(mapa,i,j+1)
                    check(mapa,i-1,j-1)
                    check(mapa,i-1,j+1)
            elif(i>0 and j==columnas-1):
                if mapa[i][j] == '*':
                    check(mapa,i-1,j)
                    check(mapa,i+1,j)
                    check(mapa,i,j-1)
                    check(mapa,i+1,j-1)
                    check(mapa,i-1,j-1)
            elif(i>0 and j>0):
                if mapa[i][j] == '*':
                    check(mapa,i,j+1)
                    check(mapa,i,j-1)
                    check(mapa,i+1,j)
                    check(mapa,i-1,j)
                    check(mapa,i+1,j-1)
                    check(mapa,i+1,j+1)
                    check(mapa,i-1,j+1)
                    check(mapa,i-1,j-1)
  

#main
lista=formateo()
renglones = int (lista.pop(0))
columnas = int (lista.pop(0))
mapa=matrizMapa(lista,renglones,columnas)
#print(mapa)
mapafinal=bombasActivas(mapa,renglones,columnas)
imprimirMapa(mapa,renglones,columnas)


#mapa[i][j]