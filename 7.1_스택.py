# last in frist out , LIFO
#  책상 위에 쌓여 있는 책


class Stack(object):
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return not ( bool(self.items) )

    def push(self, value):
        self.items.append(value)

    def pop(self):
        value = self.items.pop()

        if value != [] :
            return value
        else:
            print("Stack is empty")                   

    def size(self):
        return len(self.items)

    def peek(self):
        if self.items != []:
            return self.items[-1]
        else:
            print("Stack is empty")
            
    def __repr__(self):
        return repr(self.items)

if __name__ == "__main__":
    stack = Stack()
    print("Stack is empty? {0}".format(stack.isEmpty()))
    print("choose number N")
    N = int(input())
    print("Stack append 0 ~ N-1.")
    for i in range(N):
        stack.push(i)

    print("Stack size:{0}".format(stack.size()))
    print("peek:{0}".format(stack.peek()))
    print("pop:{0}".format(stack.pop()))
    print("peek:{0}".format(stack.peek()))
    print("Is stack is empty?:{0}".format(stack.isEmpty()))



        