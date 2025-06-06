export const tournamentTally = (input) => {
  let teams = {};

  input.split("\n").forEach(line => {
    if (line.trim() == "") return;
    let [team1, team2, outcome] = line.split(";");
    if (Object.keys(teams).indexOf(team1) == -1){
      teams[team1] = {
        "matchesPlayed": 0,
        "wins": 0,
        "draws": 0,
        "losses": 0,
        "points": 0,
      }
    }
    if (Object.keys(teams).indexOf(team2) == -1){
      teams[team2] = {
        "matchesPlayed": 0,
        "wins": 0,
        "draws": 0,
        "losses": 0,
        "points": 0,
      }
    }

    teams[team1].matchesPlayed++;
    teams[team2].matchesPlayed++;

    if (outcome == "win"){
      teams[team1].wins++;
      teams[team2].losses++;
      teams[team1].points += 3;
    } else if (outcome == "loss"){
      teams[team1].losses++;
      teams[team2].wins++;
      teams[team2].points += 3;
    } else if (outcome == "draw"){
      teams[team1].draws++;
      teams[team2].draws++;
      teams[team1].points++;
      teams[team2].points++;
    }

  });

  let header = `${"Team".padEnd(30)} | MP |  W |  D |  L |  P`;

  let rows = Object.entries(teams).sort(([team1, data1], [team2, data2]) => {
    if (data1.points > data2.points) return -1;
    else if (data1.points < data2.points) return 1;
    else if (team1 < team2) return -1;
    else return 1;
  }).map(([team, {matchesPlayed, wins, draws, losses, points}]) => `${team.padEnd(30)} | ${matchesPlayed.toString().padStart(2)} | ${wins.toString().padStart(2)} | ${draws.toString().padStart(2)} | ${losses.toString().padStart(2)} | ${points.toString().padStart(2)}`);

  return [header, ...rows].join("\n");
};
