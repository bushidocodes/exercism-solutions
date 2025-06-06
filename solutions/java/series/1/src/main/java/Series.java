import java.util.List;
import java.util.ArrayList;

class Series {
    private String data;
    
    public Series(String data){
        this.data = data;
    }

    public List<String> slices(int length){
        if (length <= 0) throw new IllegalArgumentException("Slice size is too small.");
        if (length > this.data.length()) throw new IllegalArgumentException("Slice size is too big.");
        
        List<String> res = new ArrayList();
        for (int i = 0; i + length <= this.data.length(); i++) {
            res.add(this.data.substring(i, i + length));
        }

        // It doesn't seem like Java have a sliding window capability for either collections or streams.

        return res;       
    }
}