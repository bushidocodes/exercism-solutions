import java.util.Random;
import java.util.Set;
import java.util.HashSet;

class Robot {
    static Random r = new Random();
    static Set<String> existingNames = new HashSet<>();

    static char getRandomLetter() {
        return (char)(r.nextInt(26) + 'A');
    }

    static String getRandomDigits() {
        return String.format("%03d", r.nextInt(1000));
    }

    static String generateName() {
        StringBuilder nameBuilder = null;
        String name = null;
        do {
            nameBuilder = new StringBuilder();
            nameBuilder.append(getRandomLetter());
            nameBuilder.append(getRandomLetter());
            nameBuilder.append(Robot.getRandomDigits());
            name = nameBuilder.toString();
        } while (Robot.existingNames.contains(name));

        Robot.existingNames.add(name);
        return name;
    }

    private String name;
    
    public Robot() {
        this.name = Robot.generateName();
    }

    public void reset() {
        this.name = Robot.generateName();
    }

    public String getName(){
        return this.name;
    }
}