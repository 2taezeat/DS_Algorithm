class TimeIterator:
    def __init__(self, start, stop):
        self.stop = stop
        self.start = start

    def __getitem__(self,index):
        if index < self.stop - self.start:
            time = self.start + index

            if time // 3600 >= 24:
                time = time - 24*3600
            
            hour = time // 3600
            minute = (time % 3600 ) // 60 
            second = time % 60

            return '{0:0>2d}:{1:0>2d}:{2:0>2d}'.format(hour,minute,second)

        else:
            raise IndexError


start, stop, index = map(int, input().split())
 
for i in TimeIterator(start, stop):
    print(i)
 
print('\n', TimeIterator(start, stop)[index], sep='')