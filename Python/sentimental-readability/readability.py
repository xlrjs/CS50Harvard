from cs50 import get_string
import math


def main():
    text = get_string("Text: ")

    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    index = 0  # formula
    l = 0  # average number of letter per 100 words
    s = 0  # average number of sentences per 100 words.

    l = (letters / words) * 100
    print("", l)
    s = (sentences / words) * 100
    print("", s)

    index = (0.0588 * l) - (0.296 * s) - 15.8
    print("", index)

    if (math.ceil(index)) >= 16:
        print("Grade 16+")
    elif math.ceil(index) < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {round(index)}")


def count_letters(text):
    c_words = 0  # we set a counter for the number of words
    i = 0  # we set a external iterator so it can index the string
    for j in text:  # this is a for loop, the a iterator will be added plus 1 automatically, this doesn't interfer with the i iterator
        if (text[i] >= 'a' and text[i] <= 'z') or (text[i] >= 'A' and text[i] <= 'Z'):
            c_words += 1
        i += 1
    print(f"Number of letters : {c_words}")
    return c_words


def count_words(text):
    s_words = 1
    i = 0
    for j in text:
        if text[i] == " ":
            s_words += 1
        i += 1
    print(f"Number of words: {s_words}")
    return s_words


def count_sentences(text):
    sent_w = 0
    i = 0
    for j in text:
        if (text[i] == '.' or text[i] == '?' or text[i] == '!'):
            sent_w += 1
        i += 1
    print(f"Number of sentences: {sent_w}")
    return sent_w


main()