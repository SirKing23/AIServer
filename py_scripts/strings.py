# string_operations.py - String processing functions for C++ integration

def process_string(text):
    """Process a string by making it uppercase and adding a prefix."""
    return f"PROCESSED: {text.upper()}"

def reverse_string(text):
    """Reverse the input string."""
    return text[::-1]

def count_vowels(text):
    """Count the number of vowels in the string."""
    vowels = "aeiouAEIOU"
    return sum(1 for char in text if char in vowels)

def count_words(text):
    """Count the number of words in the string."""
    return len(text.split())

def to_title_case(text):
    """Convert string to title case."""
    return text.title()

def remove_spaces(text):
    """Remove all spaces from the string."""
    return text.replace(" ", "")

def encrypt_caesar(text, shift=3):
    """Simple Caesar cipher encryption."""
    result = ""
    for char in text:
        if char.isalpha():
            ascii_offset = 65 if char.isupper() else 97
            encrypted_char = chr((ord(char) - ascii_offset + shift) % 26 + ascii_offset)
            result += encrypted_char
        else:
            result += char
    return result

def decrypt_caesar(text, shift=3):
    """Simple Caesar cipher decryption."""
    return encrypt_caesar(text, -shift)

def is_palindrome(text):
    """Check if the text is a palindrome (ignoring spaces and case)."""
    cleaned = ''.join(char.lower() for char in text if char.isalnum())
    return cleaned == cleaned[::-1]

def extract_numbers(text):
    """Extract all numbers from the text and return as a list of integers."""
    import re
    numbers = re.findall(r'\d+', text)
    return [int(num) for num in numbers]

def word_frequency(text):
    """Count frequency of each word in the text."""
    words = text.lower().split()
    frequency = {}
    for word in words:
        # Remove punctuation
        word = ''.join(char for char in word if char.isalnum())
        if word:
            frequency[word] = frequency.get(word, 0) + 1
    return frequency

def wordPlusKing(text):
    """ add king to the text"""
    return text + "king"

if __name__ == "__main__":
    # Test the functions
    test_text = "Hello World from Python!"
    print("Testing string_operations.py:")
    print(f"process_string('{test_text}') = {process_string(test_text)}")
    print(f"reverse_string('{test_text}') = {reverse_string(test_text)}")
    print(f"count_vowels('{test_text}') = {count_vowels(test_text)}")
    print(f"count_words('{test_text}') = {count_words(test_text)}")
    print(f"encrypt_caesar('{test_text}') = {encrypt_caesar(test_text)}")
    print(f"is_palindrome('racecar') = {is_palindrome('racecar')}")
