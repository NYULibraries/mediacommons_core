#!/bin/bash -e

# $ ./bin/core.sh

SOURCE="${BASH_SOURCE[0]}"

# resolve $SOURCE until the file is no longer a symlink
while [ -h "$SOURCE" ]; do
  DIR="$( cd -P "$( dirname "$SOURCE" )" && pwd )"
  SOURCE="$(readlink "$SOURCE")"
  # if $SOURCE was a relative symlink, we need to resolve it
  # relative to the path where the symlink file was located
  [[ $SOURCE != /* ]] && SOURCE="$DIR/$SOURCE"
done

# App root
APP_ROOT="$( cd -P "$( dirname "$SOURCE" )" && pwd )/.."

task=$(basename -- "$0")

timestamp=`date +%Y-%m-%d-%H:%M:%S`

die () {
  echo "file: ${0} | line: ${1} | step: ${2} | message: ${3}";
  exit 1;
}

cleanup () {
  if [[ -f ${APP_ROOT}/${task}.pid ]];
    then
      rm -f ${APP_ROOT}/${task}.pid
  fi
  cd -
}

if [[ -f ${APP_ROOT}/${task}.pid ]];
  then
    die ${LINENO} "error" "Fail: Process already running."
  else
    # Go to app root
    cd $APP_ROOT
    trap cleanup EXIT
fi

cd $APP_ROOT

echo $$ > ./${task}.pid

version=`./bin/version.php`

tar --exclude='./drupal/sites/localhost.*' -zcvf ./backups/mediacommons-${version}.${timestamp}.tar.gz ./drupal

if [ $? -eq 1 ]; then 
  die ${LINENO} "error" "Unable to create backups."
fi

./bin/core.latest.version.php

exit 0
