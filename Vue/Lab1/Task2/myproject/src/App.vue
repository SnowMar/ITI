<template>
  <div class="container mt-4">
    <h1 class="text-center">Open Source New Capital</h1>
    
    <button class="btn btn-primary my-3" @click="showModal = true">Add</button>

    <StudentTable :students="students" />

    <StudentForm v-if="showModal" @close="showModal = false" @add-student="addStudent" />
  </div>
</template>

<script>
import StudentTable from "./components/StudentTable.vue";
import StudentForm from "./components/StudentForm.vue";

export default {
  components: { StudentTable, StudentForm },
  data() {
    return {
      students: [
        { id: 100, name: "Moustafa", city: "meet ghamr" },
        { id: 200, name: "ahmed", city: "cairo" },
        { id: 300, name: "mohamed", city: "alex" },
        { id: 400, name: "Ibrahim", city: "mahala" },
      ],
      showModal: false,
    };
  },
  methods: {
    addStudent(newStudent) {
      this.students.push(newStudent);
      this.showModal = false;
    },
  },
};
</script>
