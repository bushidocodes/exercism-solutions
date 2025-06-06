export const cost = (books = []) => {
  if (books.length === 0) return 0;
  
  /* Reduce into multiset */
  let multiset = books.reduce((acc, cur) => {
    acc[cur] = (acc[cur] ?? 0) + 1;
    return acc;
  }, {});

  /* Order by count in reverse to be able to splice later */
  let multisetKV = Object.entries(multiset);
  if (multisetKV.length > 1) {
    multisetKV.sort((first, second) => first[1] - second[1]);
  }

  /* The books with the highest count determines the total groupings */
  let [firstId, firstCount] = multisetKV.pop();
  let toAdd = [firstId];

  /* Other books might have the same count */
  let otherIds = multisetKV.filter(([k,v]) => v == firstCount).map(([k,v]) => k);
  while (multisetKV.length > 0 && multisetKV[multisetKV.length - 1][1] == firstCount){
    let [id, count] = multisetKV.pop();
    toAdd.push(id);
  }

  /* Populate groups with books with identical highest count */
  let groups = [];
  for (let i = 0; i < firstCount; i++) {
    groups.push(new Set(toAdd));
  }
  
  /* Average cost of each book in a group */
  /* of 1 = $8.00 */
  /* of 2 = $7.60 */
  /* of 3 = $7.20 */
  /* of 4 = $6.40 */
  /* of 5 = $6.00 */
  /* The only meaningful grouping is groups of four. All others lower per book cost by $0.40, so try to get groups of four, then get greedy */
  const costPerGroupSizeCents = {
    1: 800,
    2: 1520,
    3: 2160,
    4: 2560,
    5: 3000 
  }

  outer:
  for (let groupID = 0; groupID < groups.length; groupID++){
    for (let i = multisetKV.length - 1; i >= 0; i--) {
      /* If group has four, advance */
      if (groups[groupID].size == 4) continue outer;
      /* If we can't fill up a group to four, abort to use different placement strategy */
      if (multisetKV.length < 4 - groups[groupID].size) break outer;
      
      if (multisetKV[i][1] > 0) {
        groups[groupID].add(multisetKV[i][0]);
        multisetKV[i][1]--;
      }
      if (multisetKV[i][1] === 0) multisetKV.splice(i, 1);
    }
  }

  /* Now that we've maximized groups of four, just pack from left to right */
  if (multisetKV.length > 0){
    for (let i = multisetKV.length - 1; i >= 0; i--) {
      let groupID = 0;
      while (multisetKV[i][1] > 0) {
        if (!multisetKV[i][1]) break;
        if (!groups[groupID].has(multisetKV[i][0])) {
          groups[groupID].add(multisetKV[i][0]);
          multisetKV[i][1]--;
        }
        groupID++;
      }
      multisetKV.splice(i, 1);
    }
  }
  
  return groups.reduce((totalCost, currentGroup) => totalCost + costPerGroupSizeCents[currentGroup.size], 0);
};
