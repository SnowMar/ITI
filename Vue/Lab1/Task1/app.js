const app = Vue.createApp({
        data() {
            return {
                books: [
                    { ISBN: "123456789", Name: "Vue.js Basics", Category: "Programming", Image: "https://m.media-amazon.com/images/I/614u486yo2L._AC_UF1000,1000_QL80_.jpg", Pages: 40, Author: "Mohamed Nagy", Price: "150" },
                    { ISBN: "987654321", Name: "Mastering Vue", Category: "Development", Image: "https://m.media-amazon.com/images/I/61YVFArzZ8L._AC_UF1000,1000_QL80_.jpg", Pages: 120, Author: "Mohamed Nagy", Price: "250" }
                    ],
                    wishlist: []
                };
            },
            methods:{
                addToWishlist(book) {
                    if(this.wishlist.includes(book)) {
                        alert("Book already in the list!");
                    }
                    this.wishlist.push(book);
                },
                removeFromWishlist(book) {
                    this.wishlist = this.wishlist.filter(b => b !== book);
                }
            }
});

app.component("book-card", {
    template: `
        <div class="row">
            <div class="col-md-4" v-for="book in books" :key="book.ISBN">
                <div class="card p-2" :class="book.Pages < 50 ? 'less' : 'more'">
                    <img :src="book.Image" class="card-img-top" alt="Book Image">
                    <div class="card-body">
                        <h5 class="card-title">{{ book.Name }}</h5>
                        <p class="card-text">Category: {{ book.Category }}</p>
                        <p class="card-text">Author: {{ book.Author }}</p>
                        <p class="card-text">Pages: {{ book.Pages }}</p>
                        <p class="card-text">Price: {{ formatPrice(book.Price) }}</p>
                        <button class="btn btn-primary" @click="addToWishlist(book)">Add to List</button>
                    </div>
                </div>
            </div>
        </div>
    `,
    props: ["books"],
    methods: {
        formatPrice(price) {
            return new Intl.NumberFormat("en-SA", { style: "currency", currency: "SAR" }).format(price);
        },
        addToWishlist(book) {
            this.$emit("add-to-wishlist", book);
        }
    }
});

app.component("wishlist-table", {
    template: `
        <div class="mt-4">
            <h3>Wishlist</h3>
            <table class="table">
                <thead>
                    <tr>
                        <th>Name</th>
                        <th>Author</th>
                        <th>Price</th>
                        <th>Remove</th>
                    </tr>
                </thead>
                <tbody>
                    <tr v-for="book in wishlist" :key="book.ISBN">
                        <td>{{ book.Name }}</td>
                        <td>{{ book.Author }}</td>
                        <td>{{ formatPrice(book.Price) }}</td>
                        <td><button class="btn btn-danger" @click="removeFromWishlist(book)">Remove</button></td>
                    </tr>
                </tbody>
            </table>
        </div>
    `,
    props: ["wishlist"],
    methods: {
        formatPrice(price) {
            return new Intl.NumberFormat("en-SA", { style: "currency", currency: "SAR" }).format(price);
        },
        removeFromWishlist(book) {
            this.$emit("remove-from-wishlist", book);
        }
    }
});


app.mount("#app");

