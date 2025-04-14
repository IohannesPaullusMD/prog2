const { exec } = require('child_process');

const fileName = 'app.exe'
const headers = [
  '2025-03-26/name',
  '2025-03-26/string',
  '2025-03-26/date',
  '2025-03-26/student',
  '2025-03-26/student_array_list',
  '2025-03-26/student_linked_list'
];
const sources = [
  "2025-03-26/student_array_list/student_array_list.c",
  "2025-03-26/student_linked_list/student_linked_list.c",
  "2025-03-26/student/student.c",
  "2025-03-26/date/date.c",
  "2025-03-26/name/name.c",
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
      // console.error(stderr);
    } else {
      console.log(stdout);
    }
};

exec(command, output);

