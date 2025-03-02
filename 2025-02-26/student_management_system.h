#ifndef STUDENT_MANAGEMENT_SYSTEM
#define STUDENT_MANAGEMENT_SYSTEM

#define NAME_LEN 50
#define PROGRAM_LEN 10
#define GRADES_LEN 5


typedef char * String;

typedef struct
{
    char name[NAME_LEN + 1];
    char program[PROGRAM_LEN + 1];
    char sex;
    float grades[GRADES_LEN];
} 
Student;

void inputStudent(Student *s);

/**
 * NAME | PROGRAM | SEX | GRADES
 * ---- | ------- | --- | --,--,--,--,-- (AVG.XX)
 */
void displayStudents(const Student studs[], const int COUNT);

float computeStudentAverage(Student s);

Student getStudentWithHighestAverage(const Student studs[], const int COUNT);

Student getStudentWithHighestAverageInProgram(const Student studs[], const int COUNT, String program);

Student getStudentByName(const Student studs[], const int COUNT, String searchKey);

Student getStudentWithHighestGrade(const Student studs[], const int COUNT);


#endif

