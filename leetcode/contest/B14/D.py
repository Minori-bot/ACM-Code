class Solution(object):
    def countShips(self, sea: 'Sea', topRight: 'Point', bottomLeft: 'Point') -> int:
        
        if not sea.hasShips(topRight, bottomLeft):  return 0
        if bottomLeft.x == topRight.x and bottomLeft.y == topRight.y: return 1
        if bottomLeft.x == topRight.x:
            mid = (topRight.y + bottomLeft.y) // 2
            p1, p2 = Point(bottomLeft.x, mid), Point(bottomLeft.x, mid + 1)
            return self.countShips(sea, p1, bottomLeft) + self.countShips(sea, topRight, p2)
        elif bottomLeft.y == topRight.y:
            mid = (topRight.x + bottomLeft.x) // 2
            p1, p2 = Point(mid, bottomLeft.y), Point(mid + 1, bottomLeft.y)
            return self.countShips(sea, p1, bottomLeft) + self.countShips(sea, topRight, p2)
        else:
            new_x = (topRight.x + bottomLeft.x) // 2
            new_y = (topRight.y + bottomLeft.y) // 2
            return self.countShips(sea,Point(new_x, new_y), bottomLeft) + self.countShips(sea, topRight, Point(new_x + 1, new_y + 1)) + \
                   self.countShips(sea, Point(topRight.x, new_y), Point(new_x + 1, bottomLeft.y)) + \
                   self.countShips(sea, Point(new_x, topRight.y), Point(bottomLeft.x, new_y + 1))
    