const { exec } = require('child_process');

const fileName = 'main.exe'
const headers = [
  './'
];
const sources = [
  "my_header.c",
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

