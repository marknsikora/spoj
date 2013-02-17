"""SPOJ problem 346"""
__author__ = "Mark Sikora"
__date__ = "2010/01/10 19:21"
 
cointable = {0:0}
def coins(n):
    """calculate max value that can be achieved by exchanging n number of
    coins
    retunrns type int"""
    if cointable.has_key(n):
        return cointable[n]
    else:
        r = max(n, coins(n/2)+coins(n/3)+coins(n/4))
        cointable[n] = r
        return r
 
if __name__ == '__main__':
    while 1:
        try:
            z = raw_input()
            print coins(int(z))
        except:
            break
