import java.util.HashMap;

public class Blackjack {
    public static HashMap<String, Integer> cardValue;
    static {
        Blackjack.cardValue = new HashMap<String, Integer>();
        Blackjack.cardValue.put("ace", 11);
        Blackjack.cardValue.put("two", 2);
        Blackjack.cardValue.put("three", 3);
        Blackjack.cardValue.put("four", 4);
        Blackjack.cardValue.put("five", 5);
        Blackjack.cardValue.put("six", 6);
        Blackjack.cardValue.put("seven", 7);
        Blackjack.cardValue.put("eight", 8);
        Blackjack.cardValue.put("nine", 9);
        Blackjack.cardValue.put("ten", 10);
        Blackjack.cardValue.put("jack", 10);
        Blackjack.cardValue.put("queen", 10);
        Blackjack.cardValue.put("king", 10);
        Blackjack.cardValue.put("other", 0);
    }

    public int parseCard(String card) {
        var value = Blackjack.cardValue.get(card);
        return value == null ? Blackjack.cardValue.get("other") : value;
    }

    public boolean isBlackjack(String card1, String card2) {
        return this.parseCard(card1) + this.parseCard(card2) == 21;
    }

    public String largeHand(boolean isBlackjack, int dealerScore) {
        if (!isBlackjack) return "P";
        else if (dealerScore != 10 && dealerScore != 11) return "W";
        else return "S";
    }

    public String smallHand(int handScore, int dealerScore) {
        if (handScore >= 17) return "S";
        else if (handScore <= 11) return "H";
        else return dealerScore >= 7? "H" : "S";
    }

    // FirstTurn returns the semi-optimal decision for the first turn, given the cards of the player and the dealer.
    // This function is already implemented and does not need to be edited. It pulls the other functions together in a
    // complete decision tree for the first turn.
    public String firstTurn(String card1, String card2, String dealerCard) {
        int handScore = parseCard(card1) + parseCard(card2);
        int dealerScore = parseCard(dealerCard);

        if (20 < handScore) {
            return largeHand(isBlackjack(card1, card2), dealerScore);
        } else {
            return smallHand(handScore, dealerScore);
        }
    }
}
