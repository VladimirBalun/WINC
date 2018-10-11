import os
import subprocess
import os.path as path


EXAMPLES_DIR = path.abspath(path.join(os.getcwd(), '../..', 'examples'))
SUCCESS_EXIT_CODE_PROGRAM = 0


def check_examples(examples):
    count_correct_examples = 0
    for example_name in examples:
        print('- Checking example: "{0}"...'.format(example_name))
        example_full_name = path.abspath(path.join(EXAMPLES_DIR, example_name))
        exit_code = subprocess.run(example_full_name, stdout=subprocess.PIPE, stderr=subprocess.PIPE).returncode
        if exit_code == SUCCESS_EXIT_CODE_PROGRAM:
            count_correct_examples += 1
            print('--- Example "{0}" was finished successfully.'.format(example_name))
        else:
            print('XXX Warning! Example "{0}" was finished failed.'.format(example_name))
    show_result_checking_examples(len(examples), count_correct_examples)


def get_examples_from_directory():
    if not os.path.exists(EXAMPLES_DIR):
        print('Error! Directory: "{0}" isn\'t exist...'.format(EXAMPLES_DIR))
        exit()
    examples = os.listdir(EXAMPLES_DIR)
    if not examples:
        print('Error! Directory: "{0}" doesn\'t contain examples...'.format(EXAMPLES_DIR))
        exit()
    return examples


def show_result_checking_examples(count_examples, count_correct_examples):
    print("\nResult checking examples:")
    print("- Count checked examples: {0}".format(count_examples))
    print("- Count correct examples: {0}".format(count_correct_examples))
    print("- Count incorrect examples: {0}".format(count_examples - count_correct_examples))


examples_from_dir = get_examples_from_directory()
check_examples(examples_from_dir)