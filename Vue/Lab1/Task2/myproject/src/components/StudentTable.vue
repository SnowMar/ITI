<template>
    <div>
      <table class="table table-bordered">
        <thead class="table-dark">
          <tr>
            <th>ID</th>
            <th>Name</th>
            <th>City</th>
          </tr>
        </thead>
        <tbody>
          <tr v-for="student in students" :key="student.id">
            <td>{{ student.id }}</td>
            <td>{{ student.name }}</td>
            <td>{{ student.city }}</td>
          </tr>
        </tbody>
      </table>
      <p class="fw-bold">Total Number Of Students: {{ students.length }}</p>
    </div>
  </template>
  
  <script>
  export default {
    props: ["students"],
  };
  </script>
  