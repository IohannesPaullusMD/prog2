import { exec } from 'child_process';

const fileName = 'test.exe'
const headers = [
  '../error',
  '../string'
];
const sources = [
  '../error/error.c',
  'date.c',
  'date_test.c'
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

