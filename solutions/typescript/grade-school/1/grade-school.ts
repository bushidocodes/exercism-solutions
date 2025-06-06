export class GradeSchool {
  _roster: {[key: number]: string[]} = {};
  students: Set<string> = new Set();

  roster() {
    let copy: {[key: number]: string[]} = {};
    for (let grade in this._roster){
      copy[grade] = [...this._roster[grade]]
    }
    return copy;
  }

  add(name: string, gradeLevel: number) {
    if (!this._roster[gradeLevel]) this._roster[gradeLevel] = [];

    /* Enforce uniqueness of student name across grades */
    if (this.students.has(name)){
      for (let gradeIdx in this._roster){
        let i = this._roster[gradeIdx].indexOf(name);
        if (i > -1){
          this._roster[gradeIdx].splice(i, 1);
          break;
        }
      }
    } else {
      this.students.add(name)
    }
      
    this._roster[gradeLevel].push(name);
    this._roster[gradeLevel].sort();
  }

  grade(gradeLevel: number) {
    return  this._roster[gradeLevel] ? this._roster[gradeLevel].slice() : [];
  }
}
