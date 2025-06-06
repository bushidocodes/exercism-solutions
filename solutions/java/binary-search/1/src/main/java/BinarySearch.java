import java.util.List;

class BinarySearch {
    private List<Integer> haystack;
    
    public BinarySearch(List<Integer> haystack){
        // Assuming haystack is sorted;
        this.haystack = haystack;
    }

    private int indexOfSlice(int start, int end, int needle) throws ValueNotFoundException {
        if (end - start == 0) throw new ValueNotFoundException("Value not in array");
        int mid = start + ((end - start) / 2);
        int elem = this.haystack.get(mid);

        if (needle == elem){
            return mid;
        } 
        else if (mid == start) {
            throw new ValueNotFoundException("Value not in array");
        } else if (needle < elem){
            return this.indexOfSlice(start, mid, needle);
        } else {
            return this.indexOfSlice(mid, end, needle);
        }
    }

    public int indexOf(int needle) throws ValueNotFoundException {
        return this.indexOfSlice(0, this.haystack.size(), needle);
    }
}