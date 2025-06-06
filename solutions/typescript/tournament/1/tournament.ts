interface TeamRecord {
  name: string;
  matchesPlayed: number;
  wins: number;
  draws: number;
  losses: number;
  points: number;
}

export class Tournament {

  
  // eslint-disable-next-line no-unused-vars
  public tally(input: string): string {

    let teamRecords: Map<string, TeamRecord> = new Map<string, TeamRecord>();
    
    let games = input
      .split("\n")
      .map(row => row.split(";"));

    for (let game of games){
      let [teamA, teamB, result]: [string, string, string] = game as [string, string, string];
      if (!teamA || !teamB || !result) continue;
      
      if (!teamRecords.has(teamA)){
        teamRecords.set(teamA, {
          name: teamA,
          matchesPlayed: 0,
          wins: 0,
          draws: 0,
          losses: 0,
          points: 0
        });
      }

      if (!teamRecords.has(teamB)){
        teamRecords.set(teamB, {
          name: teamB,
          matchesPlayed: 0,
          wins: 0,
          draws: 0,
          losses: 0,
          points: 0
        });
      }
      let teamAObj = teamRecords.get(teamA);
      let teamBObj = teamRecords.get(teamB);

      if (!teamAObj || !teamBObj) throw new Error("Team was unexpectedly missing!");

      switch(result){
        case "win":
          teamAObj.matchesPlayed++;
          teamAObj.wins++;
          teamAObj.points += 3;
          teamBObj.matchesPlayed++;
          teamBObj.losses++;
          break;
        case "loss":
          teamAObj.matchesPlayed++;
          teamBObj.matchesPlayed++;
          teamBObj.wins++;
          teamAObj.losses++;
          teamBObj.points += 3;
          break;
        case "draw":
          teamAObj.matchesPlayed++;
          teamBObj.matchesPlayed++;
          teamAObj.draws++;
          teamBObj.draws++;
          teamAObj.points++;
          teamBObj.points++;
          break;
        default:
          throw new Error(`Invalid result. Was ${result} Should be (win|loss|draw)`)
          break;
      }
    }

    let orderedTeamRecords = [...teamRecords.values()].sort((a, b) => {
      if (a.points == b.points){
        return b.name < a.name? 1 : -1;
      } else {
        return b.points - a.points;
      }
    })

    let report = ['Team                           | MP |  W |  D |  L |  P'];

    for(let team of orderedTeamRecords){
      report.push(`${team.name.padEnd(30, ' ')} | ${team.matchesPlayed.toString().padStart(2, ' ')} | ${team.wins.toString().padStart(2, ' ')} | ${team.draws.toString().padStart(2, ' ')} | ${team.losses.toString().padStart(2, ' ')} | ${team.points.toString().padStart(2, ' ')}`);
    }

    return report.join('\n');
  }
}
