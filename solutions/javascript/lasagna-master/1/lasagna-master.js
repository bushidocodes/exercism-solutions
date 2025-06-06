export function cookingStatus(remainingTime){
  switch(remainingTime){
    case undefined:
      return "You forgot to set the timer.";
    case 0:
      return "Lasagna is done.";
    default:
      return "Not done, please wait.";
  }
}

export function preparationTime(layers = [], avgPerLayer = 2){
  return (layers.length ?? 0) * avgPerLayer;
}

export function quantities(layers = []){
  const layerCount = layers.length ?? 0;
  return {
    noodles: 50 * layers.filter(e => e === "noodles").length,
    sauce: 0.2 * layers.filter(e => e === "sauce").length
  };
}

export function addSecretIngredient(friendsList = [], myList = []){
  const secretIngredient = friendsList[friendsList.length - 1]
  if (secretIngredient) myList.push(secretIngredient);
}

export function scaleRecipe(amountsForTwoPortions = {}, desiredPortions = 2){
  const scaleFactor = desiredPortions / 2;
  const scaledAmount = {}
  for (let ingredient in amountsForTwoPortions){
    scaledAmount[ingredient] = amountsForTwoPortions[ingredient] * scaleFactor;
  }
  
  return scaledAmount;
}