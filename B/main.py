class Cube:
    def __init__(self):
        self.top = ['W' for _ in range(8)]
        self.bottom = ['Y' for _ in range(8)]
        self.middle = [[['O' for _ in range(3)] for _ in range(3)],
                       [['G' for _ in range(3)] for _ in range(3)],
                       [['R' for _ in range(3)] for _ in range(3)],
                       [['B' for _ in range(3)] for _ in range(3)]]
        self.index = {'O': 0, 'G': 1, 'R': 2, 'B': 3}
        
    def rotate(self, r):
        if r.upper() == 'W':
            self._rotate_top(r.isupper())
        elif r.upper() == 'Y':
            self._rotate_bottom(r.isupper())
        else:
            self._rotate_middle(self.index[r.upper()], r.isupper())

    def _rotate_top(self, d):
        if d:
            # Rotate top row left
            self.top = self.top[2:] + self.top[:2]
            # Rotate top middle rows left
            for i in range(len(self.middle)-1):
                self.middle[i][0], self.middle[i+1][0] = self.middle[i+1][0], self.middle[i][0]
        else:
            for _ in range(3): self._rotate_top(True)

    def _rotate_bottom(self, d):
        if d:
             for _ in range(3): self._rotate_bottom(False)
        else:
            # Rotate bottom row left
            self.bottom = self.bottom[2:] + self.bottom[:2]
            # Rotate bottom middle rows left
            for i in range(len(self.middle)-1):
                self.middle[i][2], self.middle[i+1][2] = self.middle[i+1][2], self.middle[i][2]
                   
    def _rotate_middle(self, i, d):
        if d:
            # Rotate clockwise
            self.middle[i] = [list(l) for l in zip(*reversed(self.middle[i]))]
            # Swap top and right
            itop = -1 + 2*i
            iright = (i+1)%4
            for j in range(3):
                self.top[itop+j], self.middle[iright][j][0] = self.middle[iright][j][0], self.top[itop+j]
            # Swap bottom and left
            ibottom = itop
            ileft = (i+3)%4
            for j in range(3):
                self.middle[ileft][j][-1], self.bottom[ibottom+j] = self.bottom[ibottom+j], self.middle[ileft][j][-1]
            # Swap and reverse top and bottom
            for j in range(3):
                self.top[itop+j], self.bottom[ibottom+2-j] = self.bottom[ibottom+2-j], self.top[itop+j]
        else:
            for _ in range(3): self._rotate_middle(i, True)

    def print(self):
        self._print_top_bottom(self.top)
        for i in range(3):
            self._print_middle(i)
        self._print_top_bottom(self.bottom)
        print()

    def _print_middle(self, s):
        for m in self.middle:
            print(f"{''.join(m[s])}", end="|")
        print()

    def _print_top_bottom(self, row):
        print(f" {' '.join(row)}")

c = Cube()
c.print()

rotations = input()
for r in rotations:
    c.rotate(r)

    print(f"rotation: {r}") 
    c.print()
