import java.util.ArrayList;
import java.util.List;

class Allergies {
    int score;

    Allergies(int allergyScore) {
        this.score = allergyScore;
    }

    public boolean isAllergicTo(Allergen thingToCheck) {
        return (thingToCheck.getScore() & this.score) > 0;
    }

    public List<Allergen> getList() {
        List<Allergen> result = new ArrayList<>();

        for (Allergen allergen : Allergen.values()) {
            if (this.isAllergicTo(allergen))
                result.add(allergen);
        }

        return result;
    }

}