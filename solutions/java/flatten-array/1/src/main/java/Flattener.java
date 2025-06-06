import java.util.List;
import java.util.ArrayList;
import java.util.stream.Collectors;
import java.util.Collection;

class Flattener {
    public Flattener(){}

    List<Object> flatten(List<Object> input) {
        var result = new ArrayList<Object>();

        for (var o: input){
            if (o instanceof List) {
                result.addAll(this.flatten((List)o));
            } else {
                result.add(o);
            }
        }
        return result.stream().filter(o -> o != null).toList();
    }
    
}