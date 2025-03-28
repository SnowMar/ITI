<template>
    <div>
      <h2>Products</h2>
      <ul>
        <li v-for="product in products" :key="product.id">
          {{ product.name }} - ${{ product.price }}
        </li>
      </ul>
    </div>
  </template>
  
  <script>
  import { useProductStore } from '../store/productStore';
  import { onMounted } from 'vue';
  
  export default {
    setup() {
      const store = useProductStore();
      onMounted(() => store.fetchProducts());
      return { products: store.products };
    }
  };
  </script>
  