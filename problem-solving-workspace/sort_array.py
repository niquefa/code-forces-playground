from sys import stdin

def get_reverse(array, inicio, final):
    reversed_array = []
    for elemento in array:
        reversed_array.append(elemento)
    lim = final
    for var in range(inicio,final):
        temp = reversed_array [var]
        reversed_array [var] = reversed_array[lim]
        reversed_array[lim] = temp
        lim = lim - 1
        if reversed_array == sorted(array):
            break
    return reversed_array

def get_data(n, array):
    array_finale = sorted(array)
    if array == array_finale:
        return [1,1]
    for cont in range(n-1):
        print("Checking " + str(cont))
        if array[cont] > array[cont+1]:
            inicio = cont
            for pos in range(inicio + 1,n-1):
                if array[pos] < array[pos + 1]:
                    reversed_array = get_reverse(array,inicio,pos)
                    if reversed_array == array_finale:
                        return[inicio + 1,pos + 1]
                    else:
                        return []
            reversed_array = get_reverse(array,inicio,n-1)
            if reversed_array == array_finale:
                return[inicio + 1,n]
            else:
                return []

def main():
    n = int(stdin.readline().strip())
    array = [int(x) for x in stdin.readline().split()]
    segments = get_data(n, array)
    print(( "yes\n"+str(segments[0])+" "+str(segments[1]) ) if len(segments) != 0 else "no" )
main()