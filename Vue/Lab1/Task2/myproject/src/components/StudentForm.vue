<template>
    <div class="modal-overlay">
      <div class="modal-dialog">
        <div class="modal-content">
          <div class="modal-header">
            <h5 class="modal-title">Add Student</h5>
            <button class="btn-close" @click="$emit('close')"></button>
          </div>
          <div class="modal-body">
            <div class="mb-3">
              <label class="form-label">ID</label>
              <input type="number" class="form-control" v-model="student.id">
            </div>
            <div class="mb-3">
              <label class="form-label">Name</label>
              <input type="text" class="form-control" v-model="student.name">
            </div>
            <div class="mb-3">
              <label class="form-label">City</label>
              <input type="text" class="form-control" v-model="student.city">
            </div>
          </div>
          <div class="modal-footer">
            <button class="btn btn-success" @click="submitStudent">OK</button>
            <button class="btn btn-danger" @click="$emit('close')">Cancel</button>
          </div>
        </div>
      </div>
    </div>
  </template>
  
  <script>
  export default {
    data() {
      return {
        student: { id: "", name: "", city: "" }
      };
    },
    methods: {
      submitStudent() {
        if (this.student.id && this.student.name && this.student.city) {
          this.$emit("add-student", { ...this.student });
          this.student = { id: "", name: "", city: "" };
        } else {
          alert("All fields are required.");
        }
      }
    }
  };
  </script>
  
  <style>
  .modal-overlay {
    position: fixed;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    background: rgba(0, 0, 0, 0.5);
    display: flex;
    justify-content: center;
    align-items: center;
  }
  .modal-dialog {
    background: white;
    padding: 20px;
    border-radius: 5px;
  }
  </style>
  