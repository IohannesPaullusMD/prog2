const { exec } = require('child_process');

const fileName = 'app.exe'
const headers = [
  'name',
  'string',
  'date',
  'student',
  'student_array_list',
  'student_linked_list'
];
const sources = [
  "student_array_list/student_array_list.c",
  "student_linked_list/student_linked_list.c",
  "student/student.c",
  "date/date.c",
  "name/name.c",
  "main.c"
];

const headerFlags = headers.map(header => `-I ${header}`).join(' ');
const sourceFiles = sources.join(' ');
const command = `gcc ${headerFlags} ${sourceFiles} -o ${fileName}`;
const output = (error, stdout, stderr) => {
    if (error) {
      console.error(error.message);
    }
    else if (stderr) {
      console.error(stderr);
    } else {
      console.log(stdout);
    }
};

exec(command, output);

