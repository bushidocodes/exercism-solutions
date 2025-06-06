export class GradeSchool {
  #roster = {};
  roster() {
    return JSON.parse(JSON.stringify(this.#roster));
  }

  add(name, grade) {
    for (let grade of Object.keys(this.#roster)) {
      let idx = this.#roster[grade].indexOf(name);
      if (idx != -1) {
        this.#roster[grade].splice(idx, 1);
      }
    }

    if (!this.#roster[grade]) this.#roster[grade] = [name];
    else {
      this.#roster[grade].push(name);
      this.#roster[grade].sort();
    }
  }

  grade(grade) {
    return this.#roster[grade] ? [...this.#roster[grade]] : [];
  }
}
