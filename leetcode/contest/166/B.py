class Solution:
    def groupThePeople(self, groupSizes):
        record = {}
        for i in groupSizes:
            if i not in record.keys():
                record[i] = []

        for i in range(len(groupSizes)):
            record[groupSizes[i]].append(i)
        ret = []
        for key, value in record.items():
            cur, lst = 0, []
            for e in value:
                cur += 1
                lst.append(e)
                if cur == key:
                    ret.append(lst)
                    cur, lst = 0, []
        return ret