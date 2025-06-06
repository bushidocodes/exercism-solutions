import java.util.Map;
import java.util.HashMap;
import java.util.Collection;
import java.util.ArrayList;

class TeamRecord {
    public String name;
    public int matchesPlayed;
    public int wins;
    public int draws;
    public int losses;
    public int points;
    
    TeamRecord(String name, int matchesPlayed, int wins, int draws, int losses, int points) {
        this.name = name;
        this.matchesPlayed = matchesPlayed;
        this.wins = wins;
        this.draws = draws;
        this.losses = losses;
        this.points = points;
    }
}

class Tournament {
    private Map<String,TeamRecord> teamRecords;

    Tournament() {
        this.teamRecords = new HashMap();
    }

    public void applyResults(String input){
        var lines = input.split("\n");

        for (var line: lines){
            var tokens = line.split(";");
            var teamA = tokens[0];
            var teamB = tokens[1];
            var result = tokens[2];

            // Add team a if missing
            if (!this.teamRecords.containsKey(teamA)){
                this.teamRecords.put(teamA, new TeamRecord(teamA, 0, 0, 0, 0, 0));
            }
            // Add team b if missing
            if (!this.teamRecords.containsKey(teamB)){
                this.teamRecords.put(teamB, new TeamRecord(teamB, 0, 0, 0, 0, 0));
            }

            var a = this.teamRecords.get(teamA);
            var b = this.teamRecords.get(teamB);

            switch(result){
                case "win":
                    if (a != null){
                        a.matchesPlayed++;
                        a.wins++;
                        a.points +=3;
                    }

                    if (b != null){
                        b.matchesPlayed++;
                        b.losses++;
                    }
                    break;
                case "loss":
                    if (a != null){
                        a.matchesPlayed++;
                        a.losses++;
                    }
                    
                    if (b != null){
                        b.matchesPlayed++;
                        b.wins++;
                        b.points +=3;
                    }
                    break;
                case "draw":
                    if (a != null){
                        a.matchesPlayed++;
                        a.draws++;
                        a.points++;
                    }
                    
                    if (b != null){
                        b.matchesPlayed++;
                        b.draws++;
                        b.points++;
                    }
                    break;
            }
        }
    }

    public String printTable(){
        String result = "Team                           | MP |  W |  D |  L |  P\n";

        // Sort TeamRecords
        Collection<TeamRecord> values = this.teamRecords.values();
        ArrayList<TeamRecord> teams = new ArrayList<>(values);
        teams.sort((TeamRecord a, TeamRecord b) -> a.points != b.points ? new Integer(b.points).compareTo(new Integer(a.points)) : a.name.compareTo(b.name));

        for (TeamRecord team: teams){
            result = result + String.format("%-30s", team.name) 
                       + " | " + String.format("%2s", team.matchesPlayed)
                       + " | " + String.format("%2s", team.wins)
                       + " | " + String.format("%2s", team.draws)
                       + " | " + String.format("%2s", team.losses)
                       + " | " + String.format("%2s", team.points)
                       + "\n";
        }
        
        return result;
    }
}