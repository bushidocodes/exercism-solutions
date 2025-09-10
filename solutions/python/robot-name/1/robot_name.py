import random


class Robot:
    used_names = set()
    
    @staticmethod
    def random_letter():
        return chr(random.randint(ord('A'), ord('Z')))
    
    @staticmethod
    def random_number():
        return random.randint(0, 9)

    @classmethod
    def generate_name(cls):
        while True:
            candidate = f"{cls.random_letter()}{cls.random_letter()}{cls.random_number()}{cls.random_number()}{cls.random_number()}"
            if candidate not in cls.used_names:
                cls.used_names.add(candidate)
                return candidate
        
    def __init__(self):
        self.name = self.generate_name()

    def reset(self):
        self.name = self.generate_name()
        