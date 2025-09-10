class PhoneNumber:

    @staticmethod
    def validate_area_code(candidate: str):
        if candidate[0] == '0':
            raise ValueError("area code cannot start with zero")
        if candidate[0] == '1':
            raise ValueError("area code cannot start with one")

    @staticmethod
    def validate_exchange_code(candidate: str):
        if candidate[0] == '0':
            raise ValueError("exchange code cannot start with zero")
        if candidate[0] == '1':
            raise ValueError("exchange code cannot start with one")
        
    def __init__(self, number):
        if any(c.isalpha() for c in number):
            raise ValueError("letters not permitted")
        if any(not c.isdigit() and c not in {'(',')','-',' ','.','+'} for c in number):
            raise ValueError("punctuations not permitted")

        candidate = "".join(c for c in number if c.isdigit())
        
        if len(candidate) < 10:
            raise ValueError("must not be fewer than 10 digits")
        elif len(candidate) == 11:
            if candidate[0] != "1":
                raise ValueError("11 digits must start with 1")
            candidate = candidate[1:]
        elif len(candidate) > 11:
            raise ValueError("must not be greater than 11 digits")
                    
        self.validate_area_code(candidate[0:3])
        self.validate_exchange_code(candidate[3:6])

        self.number = candidate
        self.area_code = candidate[:3]

    def pretty(self) -> str:
        return f"({self.area_code})-{self.number[3:6]}-{self.number[6:]}"
