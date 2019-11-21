from itertools import product


class Solution:

    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]

    def is_valid(self, x, y, n, m, grid):
        return 0 <= x < n and 0 <= y < m and grid[x][y] == '.'

    def check_move(self, cur, target, n, m, grid, box):
        q = list()
        q.append(cur)
        vis = set(q)
        if cur == target:
            return True
        while q:
            cur = q.pop(0)
            cur_x, cur_y = cur[0], cur[1]
            for i in range(4):
                new_x, new_y = cur_x + self.dx[i], cur_y + self.dy[i]
                pos = new_x, new_y
                # print(n, m, new_x, new_y)
                if 0 <= new_x < n and 0 <= new_y < m and (new_x, new_y) not in vis and grid[new_x][new_y] == '.' and pos != box:
                    if pos == target:
                        return True
                    q.append((new_x, new_y))
                    vis.add(pos)

        return False


    def minPushBox(self, grid):

        n, m = len(grid), len(grid[0])
        terminal, box, person = 0, 0, 0

        for i, j in product(range(n), range(m)):
            if grid[i][j] == 'T':   terminal = i, j
            elif grid[i][j] == 'B': box = i, j
            elif grid[i][j] == 'S': person = i, j
            if grid[i][j] != '#':   grid[i][j] = '.'

        q = list()
        q.append((box, person, 0))
        vis = set()
        while q:
            cur = q.pop(0)
            cur_box, cur_person, step = cur
            r, c = cur_box
            for i in range(4):
                new_x, new_y = r + self.dx[i], c + self.dy[i]
                next_box = new_x, new_y
                person_x, person_y = new_x - 2 * self.dx[i], new_y - 2 * self.dy[i]
                pre_person = person_x, person_y
                if(self.is_valid(new_x, new_y, n, m, grid) and self.is_valid(person_x, person_y, n, m, grid)
                        and (next_box, i) not in vis and self.check_move(cur_person, pre_person, n, m, grid, cur_box)):
                    if next_box == terminal:
                        return step + 1
                    q.append((next_box, pre_person, step + 1))
                    vis.add((next_box, i))

        return -1