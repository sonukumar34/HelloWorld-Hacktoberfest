const moment = require('moment');

exports.run = () => {
  console.log(`[${moment().format('YYYY-MM-DD HH:mm:ss')}] Hello World!`);
}
