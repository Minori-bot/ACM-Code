class Solution:
    def removeInterval(self, intervals, toBeRemoved):

        a, b = toBeRemoved[0], toBeRemoved[1]
        ret = []
        for sgm in intervals:
            l, r = min(sgm), max(sgm)
            if l > a and r < b:
                continue
            else:
                if l <= a:
                    if r >= a:
                        ret.append([l, a])
                    else:
                        ret.append([l, r])
                if r >= b:
                    if l <= b:
                        ret.append([b, r])
                    else:
                        ret.append([l, r])
        for sgm in ret:
            if sgm[0] == sgm[1]:
                ret.remove(sgm)
        return ret