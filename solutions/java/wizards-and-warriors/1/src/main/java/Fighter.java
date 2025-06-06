abstract class Fighter {

    boolean isVulnerable() {
        return false;
    }

    public String toString(){
        return "Fighter is a Fighter";
    }

    abstract int damagePoints(Fighter fighter);

}

class Warrior extends Fighter {

    @Override
    public String toString() {
        return "Fighter is a Warrior";
    }

    @Override
    int damagePoints(Fighter wizard) {
        return wizard.isVulnerable() ? 10 : 6;
    }
}

class Wizard extends Fighter {
    private boolean didPrepareSpell = false;

    @Override
    public String toString() {
        return "Fighter is a Wizard";
    }

    @Override
    boolean isVulnerable() {
        return this.didPrepareSpell == false;
    }

    @Override
    int damagePoints(Fighter warrior) {
        return this.didPrepareSpell ? 12 : 3;
    }

    void prepareSpell() {
        this.didPrepareSpell = true;
    }

}
