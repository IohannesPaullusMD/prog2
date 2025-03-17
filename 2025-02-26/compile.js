import { exec } from 'child_process';

const fileName = 'test.exe'
const headers = [
  './'
];
const sources = [
  "student_management_system.c",
  "sts_test.c"
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

