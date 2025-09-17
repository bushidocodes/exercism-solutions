from collections import Counter
from dataclasses import dataclass


# Create a Card dataclass with a suit and a value
@dataclass(frozen=True)
class Card:
    value: int
    suit: str

    @classmethod
    def from_str(cls, card_str: str) -> "Card":
        """Create a Card from a card string like '10H' or 'AS'."""
        value = get_card_value(card_str)
        suit = card_str[-1]
        return cls(value=value, suit=suit)

    def __str__(self) -> str:
        """Return a compact string like '10H' or 'AS'."""
        value_map = {11: "J", 12: "Q", 13: "K", 14: "A"}
        value_str = value_map.get(self.value, str(self.value))
        return f"{value_str}{self.suit}"

    def __repr__(self) -> str:
        return f"Card(value={self.value}, suit={self.suit!r})"


def get_card_value(card: str) -> int:
    match card[0:-1]:
        case "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9" | "10":
            return int(card[0:-1])
        case "J":
            return 11
        case "Q":
            return 12
        case "K":
            return 13
        case "A":
            return 14
        case _:
            raise ValueError(f"Unexpected Value {card[0:-1]}")


def get_hand_value(hand: list[Card]) -> list[int]:
    return sorted((card.value for card in hand), reverse=True)


def score_hand(hand: list[Card]) -> tuple:
    card_counts = Counter(card.value for card in hand)
    suits = [card.suit for card in hand]
    values = sorted(card_counts.keys())

    # Straight flush detection
    is_flush = len(set(suits)) == 1
    is_straight = False
    straight_high = 0
    if len(values) == 5:
        # Normal straight
        if values == list(range(values[0], values[0] + 5)):
            is_straight = True
            straight_high = values[-1]
        # Ace-low straight (A,2,3,4,5)
        elif values == [2, 3, 4, 5, 14]:
            is_straight = True
            straight_high = 5
    if is_flush and is_straight:
        return (8, straight_high)

    # Four of a kind
    quads = [value for value, count in card_counts.items() if count == 4]
    if quads:
        quad = quads[0]
        kicker = max([v for v, c in card_counts.items() if c != 4], default=0)
        return (7, quad, kicker)

    # Full house
    trips = [value for value, count in card_counts.items() if count == 3]
    pairs = [value for value, count in card_counts.items() if count == 2]
    if trips and pairs:
        return (6, trips[0], pairs[0])

    # Flush
    if is_flush:
        return (5, *sorted([card.value for card in hand], reverse=True))

    # Straight
    if is_straight:
        return (4, straight_high)

    # Three of a kind
    if trips:
        trip = max(trips)
        kickers = sorted([v for v, c in card_counts.items() if c != 3], reverse=True)
        return (3, trip, *kickers)

    # Two Pairs
    if len(pairs) == 2:
        # Two pairs: return a tuple (2, highest_pair, lowest_pair, kicker)
        high, low = sorted(pairs, reverse=True)
        kicker = max([v for v, c in card_counts.items() if c == 1], default=0)
        return (2, high, low, kicker)

    # One Pair
    if len(pairs) == 1:
        # One pair: return a tuple (1, pair_value, kickers...)
        pair = pairs[0]
        kickers = sorted([v for v, c in card_counts.items() if c == 1], reverse=True)
        return (1, pair, *kickers)

    # Hand Value
    return (0, *get_hand_value(hand))


def best_hands(hands):
    scored_hands = []
    for hand_ in hands:
        hand = [Card.from_str(c) for c in hand_.split()]
        score = score_hand(hand)
        scored_hands.append((score, get_hand_value(hand), hand))

    # Find the best score
    max_score = max(scored_hands, key=lambda x: x[:2])[:2]
    winners = [h for s, v, h in scored_hands if (s, v) == max_score]

    for i, hand in enumerate(winners):
        winners[i] = " ".join(str(c) for c in hand)

    return winners
