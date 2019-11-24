class Solution:
    def suggestedProducts(self, products, searchWord):
        ret = []
        products.sort()
        for i in range(len(searchWord)):
            string = searchWord[:i + 1]
            lst = []
            for product_string in products:
                if product_string.startswith(string) and len(lst) < 3:
                    lst.append(product_string)
            ret.append(lst)
        return ret