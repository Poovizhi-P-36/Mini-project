#include <stdio.h>

// Function to calculate grade points based on letter grades
float calculateGradePoint(char grade) {
    switch (grade) {
        case 'A':
        case 'a':
            return 4.0;
        case 'B':
        case 'b':
            return 3.0;
        case 'C':
        case 'c':
            return 2.0;
        case 'D':
        case 'd':
            return 1.0;
        case 'F':
        case 'f':
            return 0.0;
        default:
            return -1.0; // Invalid grade
    }
}

int main() {
    int numCourses;
    printf("Enter the number of courses: ");
    scanf("%d", &numCourses);

    float totalCredits = 0.0;
    float totalGradePoints = 0.0;

    for (int i = 0; i < numCourses; i++) {
        char grade;
        float credits;
        printf("Enter grade for course %d (A/B/C/D/F): ", i + 1);
        scanf(" %c", &grade);
        printf("Enter credit hours for course %d: ", i + 1);
        scanf("%f", &credits);

        float gradePoint = calculateGradePoint(grade);
        if (gradePoint == -1.0) {
            printf("Invalid grade entered. Exiting program.\n");
            return 1; // Return non-zero to indicate error
        }

        totalCredits += credits;
        totalGradePoints += (credits * gradePoint);
    }

    if (totalCredits > 0.0) {
        float cgpa = totalGradePoints / totalCredits;
        printf("CGPA: %.2f\n", cgpa);
    } else {
        printf("No courses entered. CGPA cannot be calculated.\n");
    }

    return 0;
}
