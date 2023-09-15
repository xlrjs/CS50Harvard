import csv
import sys


def main():

 # Check for command-line usage
    if len(sys.argv) != 3:
        print("Error, usage: python dna.py [database].csv [sequence].txt")
        sys.exit(1)

# Read database file into a variable
    database = []
    with open(sys.argv[1], "r") as file:
        count_read = csv.DictReader(file)  # this is just a reader, it doesn't insert data into the variable
        for i in count_read:
            database.append(i)

# Read DNA sequence file into a variable
    with open(sys.argv[2], "r") as sequence:
        dna_sequence = sequence.read()
    # print(dna_sequence)

# Find longest match of each STR in DNA sequence
    sequences = list(database[0].keys())[1:]

    # print("this are the subsequences",sequences)

    result = {}

    for values in sequences:
        result[values] = longest_match(dna_sequence, values)

    # print("this is result",result)


# Check database for matching profiles

    # print(database)

    # for each row in the database, we have to compare it against the results we have.
    # we will need to start from the 1st position in the result list
    # if the comparation of values are the same
    # pritn the name

    match = True

    for row in database:
        holder = list(result.values())
        # print(row)
        tmp_l = list(row.values())
        tmp_l = tmp_l[1:]

        tmp_l = [int(i) for i in tmp_l]  # list comprehension to convert the string values in list to interger
        # print(tmp_l)
        # print(holder)

        if tmp_l == holder:
            # print("bitch")
            print(row["name"])
            match = False

    if match == True:
        print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
