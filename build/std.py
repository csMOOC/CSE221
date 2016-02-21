def mean(data):
    """Return the sample arithmetic mean of data."""
    n = len(data)
    if n < 1:
        raise ValueError('mean requires at least one data point')
    return sum(data)/n # in Python 2 use sum(data)/float(n)

def _ss(data):
    """Return sum of square deviations of sequence data."""
    c = mean(data)
    ss = sum((x-c)**2 for x in data)
    return ss

def pstdev(data):
    """Calculates the population standard deviation."""
    n = len(data)
    if n < 2:
        raise ValueError('variance requires at least two data points')
    ss = _ss(data)
    pvar = ss/n # the population variance
    return pvar**0.5

#data = [19.138437,21.513270,23.813632]
#data = [5.628044, 5.726476, 5.818846]
#data = [7.146916, 7.007240, 7.155200]
data = [48000, 43000, 44000, 50000, 46000, 43000, 43500,43200, 43000, 43000]



print pstdev(data)
